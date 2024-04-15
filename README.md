
# UserandSensorInterface

## Description
This repository contains the ROS packages for sonar testing and waypoint navigation for an ROV. It includes tools to simulate sonar testing, visualize data in RViz, and manage waypoints.

## Prerequisites
Before running the commands in this repository, ensure that you have ROS installed along with the necessary dependencies for each package. This guide assumes you are running ROS on Ubuntu.

## Usage Instructions
To initialize the environment, run this in the main directory:
```bash
source devel/setup.sh
```

### Sonar Testing
To run the sonar simulation, use the following command:
```bash
roslaunch sonar_testing dummy.launch
```
This command launches a ROS node that simulates sonar data, which can be useful for testing purposes without needing actual hardware.

### Waypoint Navigation and Visualization
For managing waypoints and visualizing data in RViz:
```bash
roslaunch waypoint_navigation_plugin rviz.launch
```
This command starts RViz configured for waypoint management, allowing you to add, remove, and modify waypoints for the ROV.

### Real Multibeam Echo Sounder (MBE) Sonar Data Publishing
To test real MBE sonar publishing data as a ROS topic and view it in RViz, follow these steps:

1. **Run the ROS Node:**
   Ensure the MBE sonar device is connected, then run:
   ```bash
   python ros.py
   ```
   This script publishes the sonar data to a ROS topic.

2. **Open the WebRTC Example:**
   Open a web browser and navigate to the `webrtc_example.html` file located in the main directory of this repository. Ensure the sonar device is running and check that the sonar data is visible on the web page.

3. **View Sonar Data in RViz:**
   While the `ros.py` script is running and publishing data, you should also be able to view this data in RViz under the respective ROS topic configured for sonar data visualization.

### Running RealSense Camera
To operate the RealSense Camera, connect it to your laptop, then execute the following command:
```bash
roslaunch realsense2_camera rs_camera.launch
```
After running this command, ROS topics should be published and visible on RViz.
