#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <sensor_msgs/Imu.h>
#include<orientation.h>

int main( int argc, char** argv )
{
  ros::init(argc, argv, "orientation");
  IMUMSG imuobject;
  ros::spin();
}
