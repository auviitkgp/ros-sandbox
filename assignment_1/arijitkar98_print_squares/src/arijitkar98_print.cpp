#include "ros/ros.h"
#include "std_msgs/Int64.h"

void NumberCallback1(const std_msgs::Int64::ConstPtr& msg1)
{
  ROS_INFO("The number is %ld",msg1->data);
}

void NumberCallback2(const std_msgs::Int64::ConstPtr& msg2)
{
  ROS_INFO("The square is %ld",msg2->data);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "arijitkar98_print");

  ros::NodeHandle print;

  ros::Subscriber num_sub = print.subscribe("topic_numbers", 1000, NumberCallback1);
  ros::Subscriber sqr_sub = print.subscribe("topic_squares", 1000, NumberCallback2);

  ros::spin();

  return 0;
}
