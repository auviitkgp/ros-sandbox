#include "ros/ros.h"
#include "std_msgs/Int64.h"
std_msgs::Int64 my_msg;
ros::Publisher topic_squares_pub;

void topic_numbersCallback(const std_msgs::Int64::ConstPtr& msg)
{ if(ros::ok()) 
  {my_msg.data=(msg->data)*(msg->data);
topic_squares_pub.publish(my_msg);
  ROS_INFO("%d", my_msg.data);}
}

int main(int argc, char **argv)
{
 
 
  ros::init(argc, argv, "squares");

  
  ros::NodeHandle n;

  ros::Subscriber topic_numbers_sub = n.subscribe("topic_numbers", 100, topic_numbersCallback);
  topic_squares_pub = n.advertise<std_msgs::Int64>("topics_squares", 100);

 
  ros::spin();

  return 0;
}
