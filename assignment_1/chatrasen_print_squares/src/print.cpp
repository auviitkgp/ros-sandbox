/*
*********************************************************
This is the node named print.
It will subscribe to both the topics viz. "topic_numbers
and "topic_squares"
*********************************************************
Note that this node is printing the squares of numbers 
1 less than the numbers which is published by the node
"numbers". This is due to a small time lag.
*********************************************************
*/


#include "ros/ros.h"
#include "std_msgs/String.h"

using namespace ros;

  void Callback1(const std_msgs::String::ConstPtr& msg)    //callback function for topic_numbers
    {
  	ROS_INFO("topic_numbers:[%s]\n ",msg->data.c_str());
    }

  void Callback2(const std_msgs::String::ConstPtr& msg)    //callback function for topic_squares
    {
  	ROS_INFO("topic_squares:[%s]\n",msg->data.c_str());
    }


  int main(int argc,char **argv)
  {
  	init(argc, argv, "print");
  	NodeHandle s1, s2;                   //two nodes for subscription are created
	Rate loop_rate(1);
  	Subscriber sub1 = s1.subscribe("topic_numbers", 1000, Callback1);
  	loop_rate.sleep();
  	Subscriber sub2 = s2.subscribe("topic_squares", 1000, Callback2);
  	spin();
  	return 0;
  }
