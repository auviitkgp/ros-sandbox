#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>
#include <stdlib.h>
//ros::init(argc, argv, "squares");
//ros::NodeHandle n;
//ros::Publisher chatter_pub2 = n.advertise<std_msgs::String>("topic_squares", 1000);
int x=0;
void chatterCallback(const std_msgs::String::ConstPtr& msg2);
int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "squares");

  
  ros::NodeHandle n;
  ros::Publisher chatter_pub2 = n.advertise<std_msgs::String>("topic_squares", 1000);
  
  ros::Subscriber sub = n.subscribe("topic_numbers", 1000, chatterCallback);

  std_msgs::String msg;

  std::stringstream ss;
  ss << x;
  msg.data = ss.str();
  chatter_pub2.publish(msg);
  ros::spin();

  return 0;
}
void chatterCallback(const std_msgs::String::ConstPtr& msg2)
{
  ROS_INFO("I heard: [%s]", msg2->data.c_str());
  int a= atoi(msg2 ->data.c_str());
  x=a*a;
  

}