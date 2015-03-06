#include "ros/ros.h"
#include "std_msgs/Int64.h"
//including neccessary header files, using Int64 messages
#include <sstream>

 std_msgs::Int64 my_msg;

 ros::Publisher chatter_pub;
//callback function for subscribption to "topic_numbers"
void numbersCallback(const std_msgs::Int64::ConstPtr& msg)
{ 
  if(ros::ok())
  {
     
    ROS_INFO("%d", (msg->data)*(msg->data)); //square the integer
    my_msg.data=((msg->data)*(msg->data));
    chatter_pub.publish(my_msg);   //publish the message, i.e. square
  }
 
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "Squares");
 
  ros::NodeHandle n;
 
  ros::Subscriber sub = n.subscribe<std_msgs::Int64>("topic_numbers", 1000, numbersCallback); //subscribe to "topic_numbers"
  chatter_pub = n.advertise<std_msgs::Int64>("topic_squares", 1000);
//publish to "topic_squares" 
  ros::spin();

  return 0;
}
