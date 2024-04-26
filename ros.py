# #pip install websocket-server roslibpy opencv-python
# import base64
# import numpy as np
# import cv2
# # import rospy
# import roslibpy
# from websocket_server import WebsocketServer

# # ROS initialization
# client = roslibpy.Ros(host='localhost', port=9090)
# client.run()

# topic = roslibpy.Topic(client, '/camera/image_raw', 'sensor_msgs/CompressedImage')

# def new_client(client, server):
#     print("New client has connected")

# def message_received(client, server, message):
#     # Decode the base64 image
#     header, encoded = message.split(",", 1)
#     img_data = base64.b64decode(encoded)
#     np_arr = np.frombuffer(img_data, np.uint8)
#     image = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)

#     # Ensure ROS is still running
#     if not roslibpy.is_connected:
#         print("ROS is not connected. Trying to reconnect...")
#         client.run()

#     # Convert and publish the image to ROS
#     _, img_encoded = cv2.imencode('.jpg', image)
#     msg = {'format': 'jpeg', 'data': list(img_encoded.tostring())}
#     topic.publish(roslibpy.Message(msg))

# server = WebsocketServer(8080, host='0.0.0.0')
# server.set_fn_new_client(new_client)
# server.set_fn_message_received(message_received)
# print("WebSocket Server started")
# server.run_forever()

#!/usr/bin/env python
# import rospy
# from cv_bridge import CvBridge
# from sensor_msgs.msg import Image
# import base64
# import numpy as np
# import cv2
# # import websockets
# from simple_websocket_server import WebSocketServer, WebSocket
# # from websocket_server import WebsocketServer

# # Initialize ROS node
# rospy.init_node('websocket_image_publisher')

# # Create a publisher for the processed images
# image_pub = rospy.Publisher('/camera/image_raw', Image, queue_size=10)

# # CV Bridge for converting between ROS Image messages and OpenCV images
# bridge = CvBridge()

# def new_client(client, server):
#     rospy.loginfo("New client has connected")

# def message_received(client, server, message):
#     # Decode the base64 image
#     header, encoded = message.split(",", 1)
#     print(header)
#     img_data = base64.b64decode(encoded)
#     print(img_data)
#     np_arr = np.frombuffer(img_data, np.uint8)
#     image = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)
#     print(image)

#     # Check if ROS is still running
#     if not rospy.is_shutdown():
#         # Convert OpenCV image to ROS Image message and publish
#         img_msg = bridge.cv2_to_imgmsg(image, encoding="bgr8")
#         image_pub.publish(img_msg)
#     else:
#         rospy.loginfo("ROS is shutdown. Exiting...")
#         server.shutdown()

# # Create and start the WebSocket server
# server = WebsocketServer(host='0.0.0.0', port=8080)
# server.set_fn_new_client(new_client)
# server.set_fn_message_received(message_received)
# rospy.loginfo("WebSocket Server started")
# server.run_forever()

import rospy
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
import base64
import numpy as np
import cv2
from simple_websocket_server import WebSocketServer, WebSocket

# Initialize ROS node
rospy.init_node('websocket_image_publisher')

# Create a publisher for the processed images
image_pub = rospy.Publisher('/camera/image_raw', Image, queue_size=10)

# CV Bridge for converting between ROS Image messages and OpenCV images
bridge = CvBridge()

class ImageWebSocket(WebSocket):
    def handle(self):
        # # Decode the base64 image
        # header, encoded = self.data.split(",", 1)
        # img_data = base64.b64decode(encoded)
        # np_arr = np.frombuffer(img_data, np.uint8)
        # Convert bytes to a NumPy array (using blob)
        np_arr = np.frombuffer(self.data, dtype=np.uint8)
        image = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)

        # Check if ROS is still running
        if not rospy.is_shutdown():
            # Convert OpenCV image to ROS Image message and publish
            img_msg = bridge.cv2_to_imgmsg(image, encoding="bgr8")
            image_pub.publish(img_msg)
        else:
            rospy.loginfo("ROS is shutdown. Exiting...")
            self.server.shutdown()

    def connected(self):
        print(self.address, 'connected')

    def handle_close(self):
        print(self.address, 'closed')

# Create and start the WebSocket server
server = WebSocketServer('', 8080, ImageWebSocket)
rospy.loginfo("WebSocket Server started")
server.serve_forever()
