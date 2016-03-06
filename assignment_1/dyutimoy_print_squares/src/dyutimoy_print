#include "ros/ros.h"
#include "std_msgs/Int64.h"

void numCallback(const std_msgs::Int64::ConstPtr& num)
{
  ROS_INFO("number[%ld]",num->data);
  //printing the subscribered topic_numbers 
}
void squaresCallback(const std_msgs::Int64::ConstPtr& squares)
{
  ROS_INFO("squares[%ld]",squares->data);
  //printing the subscribed topic_squares
}

int main(int argc,char **argv)
{
  ros::init(argc,argv,"dyutimoy_print");
  
  ros::NodeHandle n;

  ros::Subscriber print_num_sub =n.subscribe("topic_number", 1000,numCallback);
  //subscribing to topic_number
  ros::Subscriber print_squares_sub =n.subscribe("topic_squares", 1000,squaresCallback);
  //subscribing to topic_squares
  ros::spin();

  return 0;
}
