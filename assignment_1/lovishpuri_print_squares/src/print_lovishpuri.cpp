#include "ros/ros.h"
#include "std_msgs/Int64.h"



void topic_numbersCallback(const std_msgs::Int64::ConstPtr& msg)
{ if(ros::ok()) 
  {ROS_INFO("number = %d", msg->data);}
}
void topic_squaresCallback(const std_msgs::Int64::ConstPtr& msg)
{ if(ros::ok()) 
  {  ROS_INFO("its square = %d",msg->data);}
}

int main(int argc, char **argv)
{
 
 
  ros::init(argc, argv, "print");

  
  ros::NodeHandle n;

  ros::Subscriber topic_numbers_sub = n.subscribe("topic_numbers", 100, topic_numbersCallback);

  ros::Subscriber topic_squares_sub = n.subscribe("topic_squares", 100, topic_squaresCallback);

 
  ros::spin();

  return 0;
}
