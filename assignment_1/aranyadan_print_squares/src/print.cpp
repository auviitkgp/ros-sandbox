#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>
#include <stdlib.h>

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str0);
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "squares");

  
  ros::NodeHandle n;
  
  ros::Subscriber sub = n.subscribe("topic_squares", 1000, chatterCallback);

  
  ros::spin();

  return 0;
}