#include <ros/ros.h>
#include<imu_viz_2d.h>

int main( int argc, char** argv )
{
  ros::init(argc, argv, "imu_viz_2d");
  IMUMSG imuobject;
  ros::spin();
}
