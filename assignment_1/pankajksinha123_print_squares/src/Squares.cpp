#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Int64.h>
#include <sstream>
using namespace std;
using namespace ros;
using namespace std_msgs;
Publisher cpub;
//Calling on subscription to topic_number
void Callback(const std_msgs::Int64::ConstPtr& msg)
{ 
  long int i;
  i = (msg->data) * (msg->data);
  std_msgs::Int64 msg1;
  msg1.data = i;
  ROS_INFO("%ld", i);
  cpub.publish(msg1);  
}
int main(int argc, char **argv)
{
  //Initialise square node
  init(argc, argv, "square");
  NodeHandle n2;
  //Subscribing to topicnumber
  Subscriber sub = n2.subscribe("topic_numbers", 1000, callback);
  cpub = n2.advertise<std_msgs::Int64>("topic_squares", 1000);
  spin();
  return 0;
}
