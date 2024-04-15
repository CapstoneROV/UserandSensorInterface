# UserandSensorInterface
# Repository Name

## Description
This repository contains the ROS packages for sonar testing and waypoint navigation for an ROV. It includes tools to simulate sonar testing, visualize data in RViz, and manage waypoints.

## Prerequisites
Before running the commands in this repository, ensure that you have ROS installed along with the necessary dependencies for each package. This guide assumes you are running ROS on Ubuntu.

## Usage Instructions

### Sonar Testing
To run the sonar simulation, use the following command:

```bash
roslaunch sonar_testing dummy.launch

This command launches a ROS node that simulates sonar data, which can be useful for testing purposes without needing actual hardware.
Waypoint Navigation and Visualization

For managing waypoints and visualizing data in RViz:

roslaunch waypoint_navigation_plugin rviz.launch

This command starts RViz configured for waypoint management, allowing you to add, remove, and modify waypoints for the ROV.
Real Multibeam Echo Sounder (MBE) Sonar Data Publishing

To test real MBE sonar publishing data as a ROS topic and view it in RViz, follow these steps:

    Run the ROS Node:

    Make sure the MBE sonar device is connected, then run:

python ros.py

This script publishes the sonar data to a ROS topic.

Open the WebRTC Example:

Open a web browser and navigate to the webrtc_example.html file located in the main directory of this repository. Ensure the sonar device is running and check that the sonar data is visible on the web page.

View Sonar Data in RViz:

While the ros.py script is running and publishing data, you should also be able to view this data in RViz under the respective ROS topic configured for sonar data visualization.
