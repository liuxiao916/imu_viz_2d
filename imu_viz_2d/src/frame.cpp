#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main( int argc, char** argv )
{
  ros::init(argc, argv, "imu_frame");
  ros::NodeHandle n;
  ros::Rate r(5);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("imu_frame", 10);

  while (ros::ok())
  {
    visualization_msgs::Marker x, y;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    x.header.frame_id =y.header.frame_id = "/base_link";
    x.header.stamp = y.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    x.ns=y.ns= "basic_shapes";
    x.id=0;
    y.id=1;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    x.type =y.type=visualization_msgs::Marker::ARROW;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    x.action =y.action= visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
   geometry_msgs::Point p;
   p.x=p.y=p.z=0;

    geometry_msgs::Point px;
    px.x=1;
    px.y=px.z=0;
    x.points.push_back(p);
    x.points.push_back(px);

    geometry_msgs::Point py;
    py.y=1;
    py.x=py.z=0;
    y.points.push_back(p);
    y.points.push_back(py);

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    x.scale.x =y.scale.x = 0.1;
    x.scale.y = y.scale.y = 0.5;
    x.scale.z =y.scale.z = 0.0;

    // Set the color -- be sure to set alpha to something non-zero!
    x.color.r=0.0f;
    x.color.g=0.0f;
    x.color.b=1.0f;
    x.color.a=1.0;

    y.color.r=0.0f;
    y.color.g=1.0f;
    y.color.b=0.0f;
    y.color.a=1.0;

    // Publish the marker
    marker_pub .publish(y);
    marker_pub .publish(x);

    r.sleep();
  }
}
