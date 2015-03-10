#include "ros/ros.h"
#include "std_msgs/Int32.h"

void numbersCallback(const std_msgs::Int32::ConstPtr& msg)
{
  ROS_INFO("topic_numbers says: [%d]", msg->data);
}

void squaresCallback(const std_msgs::Int32::ConstPtr& msg)
{
  ROS_INFO("topic_squares says: [%d]", msg->data);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "print");
  ros::NodeHandle n;  
  ros::Subscriber sub_numbers = n.subscribe("/topic_numbers", 100, numbersCallback); 
  ros::Subscriber sub_squares = n.subscribe("/topic_squares", 100, squaresCallback);   
  ros::spin();

  return 0;
}