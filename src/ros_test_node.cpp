#include "string.h"

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <ros/node_handle.h>

void TwistCallBack( const geometry_msgs::Twist::ConstPtr msg_)
{
  ROS_INFO("Ho ricevuto un twist! Linear = %f\n, Angular = %f\n", msg_->linear.x, msg_->angular.z);
  return;
}

int main(int argc, char **argv)
{
      ros::init(argc, argv, "ROS_Test");
      
      ros::NodeHandle l_node("~");
      ros::Subscriber l_sub = l_node.subscribe<geometry_msgs::Twist>("/red_blue/cmd_vel",1,&TwistCallBack);
      
      ros::spin();
      
      ROS_INFO("Ending Test");

      return 0;
}