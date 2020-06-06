#include <ros/ros.h>
#include <cmath>
#include <nav_msgs/Path.h>
#include <geometry_msgs/PoseStamped.h>

main (int argc, char **argv)
{
    //initalization
    ros::init (argc, argv, "showpolar_06g");
    ros::NodeHandle ph;
    ros::Rate r(5);
    ros::Publisher path_pub = ph.advertise<nav_msgs::Path>("polar_06g",1, true);

    ros::Time current_time, last_time;
    current_time = ros::Time::now();
    last_time = ros::Time::now();

    nav_msgs::Path path;
    path.header.stamp=current_time;
    path.header.frame_id="/base_link";

    //parameters about the cycle
    //centre point 
    double centre_x = 0;
    double centre_y = 0;
    //radius
    double R=9.8*0.6;
    double th = 0.0;
     double delta_th = 0.1;

    while (ros::ok())
    {

        current_time = ros::Time::now();
        //compute the cpprdinates
        double dt = 0.1;
        double x =centre_x+R*sin(th);
        double y = centre_y+R*cos(th);
        th += delta_th;

        geometry_msgs::PoseStamped this_pose_stamped;
        this_pose_stamped.pose.position.x = x;
        this_pose_stamped.pose.position.y = y;

        this_pose_stamped.header.stamp=current_time;
        this_pose_stamped.header.frame_id="/base_link";
        path.poses.push_back(this_pose_stamped);

        path_pub.publish(path);

        last_time = current_time;
        r.sleep();
    }

    return 0;
}
