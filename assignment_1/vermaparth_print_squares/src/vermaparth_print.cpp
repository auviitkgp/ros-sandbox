#include "ros/ros.h"
#include "std_msgs/Int64.h"

void chatterCallback_1(const std_msgs::Int64::ConstPtr& msg)
{
 ROS_INFO("Number : %ld", msg->data);
}

void chatterCallback_2(const std_msgs::Int64::ConstPtr& msg)
{ 
 ROS_INFO("It's Square: %ld", msg->data);
}

int main( int argc , char **argv)
{
  ros::init(argc , argv,"print");

  ros::NodeHandle n1;
  ros::NodeHandle n2;
  
  ros::Subscriber sub2 =n1.subscribe("topic_numbers", 1000, chatterCallback_1);
  ros::Subscriber sub1 =n2.subscribe("topic_squares", 1000, chatterCallback_2);

  ros::spin();
 
  return 0;

}
  
