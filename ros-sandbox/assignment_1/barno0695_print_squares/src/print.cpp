#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Int64.h>
#include <math.h>

void chatterCallback(const std_msgs::Int64::ConstPtr& msg)
{
  ROS_INFO("Numbers: %ld", msg->data);
}

void chatterCallback1(const std_msgs::Int64::ConstPtr& msg)
{
  ROS_INFO("Squares: %ld", msg->data);
}

int main(int argc, char **argv)
{
  //initialising the node print
  ros::init(argc, argv, "print");

  ros::NodeHandle n;
  ros::NodeHandle n1;

  //subscribing to topic_squares and topic_numbers
  ros::Subscriber sub1 = n1.subscribe("topic_squares", 1000, chatterCallback1);
  ros::Subscriber sub = n.subscribe("topic_numbers", 1000, chatterCallback);

  ros::spin();

  return 0;
}