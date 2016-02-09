#include "ros/ros.h"
#include "std_msgs/Int64.h"

// Callback for "topic_numbers"
void chatter1Callback(const std_msgs::Int64::ConstPtr& msg)
{
  ROS_INFO("Number: %d", msg->data);
}
// Callbackk for "topic_squares"
void chatter2Callback(const std_msgs::Int64::ConstPtr& msg)
{
  ROS_INFO("Its square: %d", msg->data);
}



int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;
  
// Subscribe to "topic_numbers" and "topic_squares"
  ros::Subscriber sub1 = n.subscribe("topic_numbers", 1000, chatter1Callback);
  ros::Subscriber sub2 = n.subscribe("topic_squares", 1000, chatter2Callback);

  ros::spin();

  return 0;
}
