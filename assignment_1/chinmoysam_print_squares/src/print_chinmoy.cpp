#include "ros/ros.h"
#include "std_msgs/Int64.h"
#include <sstream>

void chatternumberCallback(const std_msgs::Int64::ConstPtr& msg)
{
  ROS_INFO("NUMBER = %d", (int)msg->data);
}

void chattersquareCallback(const std_msgs::Int64::ConstPtr& msg1)
{
  ROS_INFO("SQUARE = %d", (int)msg1->data);
}

int main(int argc, char **argv)
{
   ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber subnumber = n.subscribe("topic_numbers",1000,chatternumberCallback);

  ros::Subscriber subsquare = n.subscribe("topic_squares",1000,chattersquareCallback);

 ros::spin();

  return 0;
}