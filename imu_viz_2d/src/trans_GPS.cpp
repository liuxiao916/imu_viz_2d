#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <novatel_msgs/INSPVAX.h>
#include<iostream>


class  TRANSGPS
{
  public:
    TRANSGPS(std::string subtopic)
    {
      pub = n.advertise<sensor_msgs::NavSatFix>("trans_GPS", 10);
      sub = n.subscribe(subtopic, 1000, &TRANSGPS::TRANS,this);
    }

void TRANS(const novatel_msgs::INSPVAX& msg);

  private:
    ros::NodeHandle n;
    ros::Subscriber sub;
    ros::Publisher pub;
};

int main( int argc, char** argv )
{
  ros::init(argc, argv, "trans_GPS");
  TRANSGPS trans(argv[1]);
  ros::spin();
}

void TRANSGPS::TRANS(const novatel_msgs::INSPVAX& msg)
{
    sensor_msgs::NavSatFix gps_data;
    gps_data.header.stamp = ros::Time::now();
    gps_data.header.frame_id = "base_link";

    gps_data.latitude=msg.latitude;
    gps_data.longitude=msg.longitude;
    gps_data.altitude=msg.altitude;
    pub.publish(gps_data);
}