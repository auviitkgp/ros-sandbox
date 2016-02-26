#include "ros/ros.h"
#include "std_msgs/Int64.h"

void numCallback(const std_msgs::Int64::ConstPtr& num)
{
  ROS_INFO("number[%ld]",num->data);
}
void squaresCallback(const std_msgs::Int64::ConstPtr& squares)
{
  ROS_INFO("squares[%ld]",squares->data);
}

int main(int argc,char **argv)
{
  ros::init(argc,argv,"dyutimoy_print");
  
  ros::NodeHandle n;

  ros::Subscriber print_num_sub =n.subscribe("topic_number", 1000,numCallback);
  ros::Subscriber print_squares_sub =n.subscribe("topic_squares", 1000,squaresCallback);

  ros::spin();

  return 0;
}
