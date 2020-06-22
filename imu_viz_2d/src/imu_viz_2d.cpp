#include <ros/ros.h>
#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <sensor_msgs/Imu.h>
#include<iostream>
#include<vector>
#include<numeric>

class  IMUMSG
{
  public:
    IMUMSG(std::string subtopic)
    {
      pub = n.advertise<visualization_msgs::Marker>("imu_viz_2d", 10);
      sub = n.subscribe(subtopic, 1000, &IMUMSG::Callback_SPHERE,this);    
    }

  void Callback_SPHERE(const sensor_msgs::Imu& msg);

  private:
    ros::NodeHandle n;
    ros::Subscriber sub;
    ros::Publisher pub;
    std::vector<double> x{std::vector<double> (10)};    // the size of smoother is 10;
    std::vector<double> y{std::vector<double> (10)};
};

int main( int argc, char** argv )
{
  ros::init(argc, argv, "imu_viz_2d");
  IMUMSG imuobject(argv[1]);
  ros::spin();
}

void IMUMSG::Callback_SPHERE(const sensor_msgs::Imu& msg)
{
  //use vector to create smoother
  x.push_back( msg.linear_acceleration.x);
  x.erase(x.begin());
  y.push_back( msg.linear_acceleration.y);
  y.erase(y.begin());

  double sum_x=accumulate(x.begin(),x.end(),0);
  double sum_y=accumulate(y.begin(),y.end(),0);
  double ave_x=sum_x/x.size();
  double ave_y=sum_y/y.size();

   visualization_msgs::Marker  imu;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
   imu.header.frame_id ="/base_link";
   imu.header.stamp=ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    imu.ns = "basic_shapes";
    imu.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    imu.type=visualization_msgs::Marker::SPHERE;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    imu.type= visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    imu.pose.position.x = ave_x;
    imu.pose.position.y = ave_y;
    imu.pose.position.z = 0;
    imu.pose.orientation.x = 0.0;
    imu.pose.orientation.y = 0.0;
    imu.pose.orientation.z = 0.0;
    imu.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side

    imu.scale.x = 0.3;
    imu.scale.y =  0.3;
    imu.scale.z = 0.1;

    // Set the color -- be sure to set alpha to something non-zero!
    imu.color.r = 1.0f;
    imu.color.g = 0.0f;
    imu.color.b = 1.0f;
    imu.color.a = 1.0;

    imu.lifetime =  ros::Duration();

    // Publish the marker
    pub.publish(imu);
}


