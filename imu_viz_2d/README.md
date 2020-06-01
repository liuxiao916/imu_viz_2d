# imu_viz_2d
Ubuntu 18.04
ROS melodic

roslaunch imu_viz_2d start.launch 
to run the package

The article about this package:
https://medium.com/@hitlx916/visualize-imu-msg-from-scratch-2d-ros-rviz-b7869a804e36?source=friends_link&sk=eedc8762c40365986bd09c0cf209ed52

# There is three cpp file 
## frame.cpp
This is to draw a coordinate. Blue arrow is x nad green is y.
Also, the orientation of greem arrow is north.

## imu_viz_2d.cpp
The function of this file is to visualize accelaration of the car in 2D.

## orientation.cpp
This file is to visualize the orientation of the vehicle in a sky blue arrow.
