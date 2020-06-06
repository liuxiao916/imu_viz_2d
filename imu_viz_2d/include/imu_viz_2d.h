#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <sensor_msgs/Imu.h>
#include<iostream>

class  IMUMSG
{
  public:
    IMUMSG()
    {
      pub = n.advertise<visualization_msgs::Marker>("imu_viz_2d", 10);
      sub = n.subscribe("/imu_raw", 1000, &IMUMSG::Callback_SPHERE,this);    // change to &IMUMSG::Callback_ARROW if you want show imu  
    }

void Callback_ARROW(const sensor_msgs::Imu& msg)
{
   visualization_msgs::Marker  imu;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
   imu.header.frame_id ="/base_link";
   imu.header.stamp=ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    imu.ns = "basic_shapes";
    imu.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    imu.type=visualization_msgs::Marker::ARROW;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    imu.type= visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    geometry_msgs::Point p;
    geometry_msgs::Point p1;
    p.x=p.y=p.z=0;
    p1.x=msg.linear_acceleration.x;
    p1.y=msg.linear_acceleration.y;
    p1.z=0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    imu.scale.x = 0.1;
    imu.scale.y =  0.5;
    imu.scale.z = 0.0;

    // Set the color -- be sure to set alpha to something non-zero!
    imu.color.r = 1.0f;
    imu.color.g = 0.0f;
    imu.color.b = 1.0f;
    imu.color.a = 1.0;

    imu.lifetime =  ros::Duration();

    // Publish the marker
    imu.points.push_back(p);
    imu.points.push_back(p1);
    pub.publish(imu);

}

void Callback_SPHERE(const sensor_msgs::Imu& msg)
{
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
    imu.pose.position.x = msg.linear_acceleration.x;
    imu.pose.position.y = msg.linear_acceleration.y;
    imu.pose.position.z = 0;
    imu.pose.orientation.x = 0.0;
    imu.pose.orientation.y = 0.0;
    imu.pose.orientation.z = 0.0;
    imu.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
<<<<<<< HEAD
    imu.scale.x = 0.3;
    imu.scale.y =  0.3;
=======
    imu.scale.x = 0.1;
    imu.scale.y =  0.1;
>>>>>>> 90286f4dd0262b2f67fe6e029cdfc8c9d4c70078
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

  private:
    ros::NodeHandle n;
    ros::Subscriber sub;
    ros::Publisher pub;
};

