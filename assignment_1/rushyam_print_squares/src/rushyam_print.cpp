#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>
#include <stdlib.h>
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("number=    %s", msg->data.c_str());
}
void chatterCallback2(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("square=    %s", msg->data.c_str());
}
int main(int argc, char **argv)
{  
  ros::init(argc, argv, "print_aranyadan");  
  ros::NodeHandle n;  
  ros::Subscriber sub = n.subscribe("topic_numbers", 1000, chatterCallback);
  ros::Subscriber sub2 = n.subscribe("topic_squares", 1000, chatterCallback2);  
  ros::spin();
  return 0;
}
