#!/usr/bin/env python

import cv2
import rospy
import time

try:
    import pubs
    import subs
    import video
except:
    import bluerov.pubs as pubs
    import bluerov.subs as subs
    import bluerov.video as video

from geometry_msgs.msg import TwistStamped
from mavros_msgs.srv import CommandBool
from sensor_msgs.msg import JointState, Joy

from sensor_msgs.msg import BatteryState
from mavros_msgs.msg import OverrideRCIn, RCIn, RCOut


class Code(object):

    """Class to provide user access

    Attributes:
        cam (Video): Video object, get video stream
        pub (Pub): Pub object, do topics publication
        sub (Sub): Sub object, subscribe in topics
    """

    def __init__(self):
        super(Code, self).__init__()

        # Do what is necessary to start the process
        # and to leave gloriously
        self.arm()

        self.sub = subs.Subs()
        self.pub = pubs.Pubs()

        self.pub.subscribe_topic('/mavros/rc/override', OverrideRCIn)
        self.pub.subscribe_topic('/mavros/setpoint_velocity/cmd_vel', TwistStamped)
        self.pub.subscribe_topic('/BlueRov2/body_command', JointState)

        self.sub.subscribe_topic('/joy', Joy)
        self.sub.subscribe_topic('/mavros/battery', BatteryState)
        self.sub.subscribe_topic('/mavros/rc/in', RCIn)
        self.sub.subscribe_topic('/mavros/rc/out', RCOut)

        self.cam = None
        try:
            video_udp_port = rospy.get_param("/user_node/video_udp_port")
            rospy.loginfo("video_udp_port: {}".format(video_udp_port))
            self.cam = video.Video(video_udp_port)
        except Exception as error:
            rospy.loginfo(error)
            self.cam = video.Video()


    def arm(self):
        """ Arm the vehicle and trigger the disarm
        """
        rospy.wait_for_service('/mavros/cmd/arming')

        self.arm_service = rospy.ServiceProxy('/mavros/cmd/arming', CommandBool)
        self.arm_service(True)

        # Disarm is necessary when shutting down
        rospy.on_shutdown(self.disarm)


    @staticmethod
    def pwm_to_thrust(pwm):
        """Transform pwm to thruster value
        The equation come from:
            https://colab.research.google.com/notebook#fileId=1CEDW9ONTJ8Aik-HVsqck8Y_EcHYLg0zK

        Args:
            pwm (int): pwm value

        Returns:
            float: Thrust value
        """
        return -3.04338931856672e-13*pwm**5 \
            + 2.27813523978448e-9*pwm**4 \
            - 6.73710647138884e-6*pwm**3 \
            + 0.00983670053385902*pwm**2 \
            - 7.08023833982539*pwm \
            + 2003.55692021905

    def run(self):
        """Run user code
        """
        while not rospy.is_shutdown():
            time.sleep(0.1)
            # Attempt to log battery voltage, RC IN, and RC OUT channels if available
            try:
                mavros_data = self.sub.get_data().get('mavros', {})
                battery_data = mavros_data.get('battery', {})
                rospy.loginfo(battery_data.get('voltage', 'Voltage data not available'))
                rospy.loginfo(mavros_data.get('rc', {}).get('in', {}).get('channels', 'RC IN channels data not available'))
                rospy.loginfo(mavros_data.get('rc', {}).get('out', {}).get('channels', 'RC OUT channels data not available'))
            except Exception as error:
                print('Get data error:', error)

            # Since joystick is disabled, we skip the part that processes joystick data
            # This means we also skip setting RC overrides based on joystick input

            try:
                # Process RC OUT data to simulate thruster commands
                rc_out_channels = self.sub.get_data().get('mavros', {}).get('rc', {}).get('out', {}).get('channels', [])
                if rc_out_channels:
                    joint = JointState()
                    joint.name = ["thr{}".format(u + 1) for u in range(len(rc_out_channels))]
                    joint.position = [self.pwm_to_thrust(pwm) for pwm in rc_out_channels]

                    self.pub.set_data('/BlueRov2/body_command', joint)
                else:
                    print('No RC out channels data available')
            except Exception as error:
                print('rc error:', error)

            # Video frame processing
            try:
                if not self.cam or not self.cam.frame_available():
                    continue

                frame = self.cam.frame()
                cv2.imshow('frame', frame)
                cv2.waitKey(1)
            except Exception as error:
                print('imshow error:', error)


    def disarm(self):
        self.arm_service(False)


if __name__ == "__main__":
    try:
        rospy.init_node('user_node', log_level=rospy.DEBUG)
    except rospy.ROSInterruptException as error:
        print('pubs error with ROS: ', error)
        exit(1)
    code = Code()
    code.run()
