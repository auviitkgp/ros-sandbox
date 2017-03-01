#include "ros/ros.h"
#include "std_msgs/Int64.h"
using namespace std;
using namespace ros;
using namespace std_msgs;
//calling back topicnumber
void c1(const std_msgs::Int64::ConstPtr& msg)
{
  ROS_INFO("Number %ld", msg->data);
}
// calling topicsqaure
void c2(const std_msgs::Int64::ConstPtr& msg)
{
  ROS_INFO("Square %ld", msg->data);
}
int main(int argc, char **argv)
{  
  //initialising node print
  init(argc, argv, "print");
  NodeHandle n1;
  NodeHandle n2;   
  //subscribing 
  Subscriber s2 = n1.subscribe("topic_numbers", 1000, c1);
  Subscriber s1 = n2.subscribe("topic_squares", 1000, c2);
  spin();
  return 0;
}
