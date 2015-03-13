
#include "ros/ros.h"
#include "std_msgs/Int64.h"

 std_msgs::Int64 my_msg;

 ros::Publisher chatter_pub;

void chatterCallback(const std_msgs::Int64::ConstPtr& msg)
{ my_msg.data=((msg->data)*(msg->data));
  ROS_INFO("I heard: [%d] converted to [%d]", msg->data,my_msg.data);
  chatter_pub.publish(my_msg);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "squares");
  ros::NodeHandle n;


  ros::Subscriber sub = n.subscribe("topic_numbers", 1000,chatterCallback);
 chatter_pub = n.advertise<std_msgs::Int64>("topic_squares", 1000);
 ros::spin();

  return 0;
}

