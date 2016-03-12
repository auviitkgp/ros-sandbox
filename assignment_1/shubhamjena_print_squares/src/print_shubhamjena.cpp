#include "ros/ros.h"
#include "std_msgs/String.h"
  

void topic_numbersCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("topic_numbers [%s]", msg->data.c_str());
}

void topic_squaresCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("topic_squares [%s]", msg->data.c_str());
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "print_shubamjena");

  ros::NodeHandle n;
  ros::Subscriber sub1 = n.subscribe("topic_numbers", 1000, topic_numbersCallback);
  ros::Subscriber sub2 = n.subscribe("topic_squares", 1000, topic_squaresCallback);  

  ros::spin();

  return 0;
}

