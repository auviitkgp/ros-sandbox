#include "ros/ros.h"
#include "std_msgs/Int64.h"

ros::Publisher chatter_pub1;
ros::Publisher chatter_pub2;

void chatterCallback1(const std_msgs::Int64::ConstPtr& msg)
{
  ROS_INFO("topic_numbers  %ld ", msg->data);
  chatter_pub1.publish(msg);

}
void chatterCallback2(const std_msgs::Int64::ConstPtr& msg)
{
  ROS_INFO("topic_squares  %ld ", msg->data);
  chatter_pub2.publish(msg);

}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "print");

  ros::NodeHandle n;
ros::Rate loop_rate(1);

 // Subscribing to topic topic_numbers
  ros::Subscriber sub1 = n.subscribe("topic_numbers", 1000, chatterCallback1);
  // Subscribing to topic topic_squares
  ros::Subscriber sub2 = n.subscribe("topic_squares", 1000, chatterCallback2);

loop_rate.sleep();  
  ros::spin();

  return 0;
}
