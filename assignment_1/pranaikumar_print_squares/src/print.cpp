#include "ros/ros.h"
#include "std_msgs/Int64.h"

//calling back on topic_numbers
void chatterCallback_1(const std_msgs::Int64::ConstPtr& msg)
{
  ROS_INFO("Number: %ld", msg->data);
}

//calling back on topic_sqares
void chatterCallback_2(const std_msgs::Int64::ConstPtr& msg)
{
  ROS_INFO("It's Square: %ld", msg->data);
}

int main(int argc, char **argv)
{
  //initialising the node print
  ros::init(argc, argv, "print");

  ros::NodeHandle n1;
  ros::NodeHandle n2;

  //subscribing to topic_squares and topic_numbers
  
  ros::Subscriber sub2 = n1.subscribe("topic_numbers", 1000, chatterCallback_1);
  ros::Subscriber sub1 = n2.subscribe("topic_squares", 1000, chatterCallback_2);

  ros::spin();

  return 0;
}
