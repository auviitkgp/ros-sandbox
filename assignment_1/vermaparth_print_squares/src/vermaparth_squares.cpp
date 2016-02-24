#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Int64.h>
#include <sstream>

 
ros::Publisher chatter_pub;

void chatterCallback(const std_msgs::Int64::ConstPtr& msg)
{ 
 long int i;

 i=(msg->data)*(msg->data);
 std_msgs::Int64 msg1;
 msg1.data = i;
 ROS_INFO("%ld",i);

 chatter_pub.publish(msg1);
}

int main(int argc, char **argv)
{
  ros::init(argc,argv,"square");
  ros::NodeHandle n2;
 
  ros::Subscriber sub=n2.subscribe("topic_numbers",1000, chatterCallback);
  chatter_pub = n2.advertise<std_msgs::Int64>("topic_squares",1000);

  ros::spin();

  return 0;

}
