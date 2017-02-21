#include "ros/ros.h"
#include "std_msgs/Int64.h"
#include <bits/stdc++.h>

using namespace std;

void sqcallback(const std_msgs::Int64::ConstPtr& sqr)  //callback function for topic_squares
{
  ROS_INFO("%ld received from topic_squares",sqr->data);
  return;
}

void numcallback(const std_msgs::Int64::ConstPtr& num) //callback function for topic_numbers
{
  ROS_INFO("%ld received from topic_numbers",num->data);
  return;
}

int main(int argc,char **argv)
{
  ros::init(argc,argv,"basher666_print");
  ros::NodeHandle n;
  ros::Rate loop_rate(1); //for 1 hz rate

  ros::Subscriber sub1=n.subscribe("topic_numbers",1000,numcallback); //subscribing to the topic_numbers
  ros::Subscriber sub2=n.subscribe("topic_squares",1000,sqcallback);  // subscribing to the topic_squares  
  ros::spin();
  loop_rate.sleep();
  return 0;
}
