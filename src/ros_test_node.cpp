#include <ros/ros.h>
#include "geometry_msgs/Twist.h"

void TwistCallBack( const geometry_msgs::Tewist::ConstPtr cmd)
{
  ROS_INF("Ho ricevuto un twist! Linear = %f\n, Angular = %f\n", cmd->linear.x, cmd->angular.z);
}

int main(int argc, char **argv)
{
      ros::init(argc, argv, "ROS_Test");
      
      ros::NodeHandle l_node("~");
      ros::Subscriber l_sub = l_node.subscribe<geometry_msgs::Twist>("/red_blue/cmd_vel",1,&TwistCallBack);
      
      ros::spin();
      
      ROS_INFO("Ending agent %s.", l_name.c_str());

      return 0;
}