#include "ros/ros.h"
#include "std_msgs/Int64.h"
//including neccessary header files, using Int64 messages
#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Numbers");
  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::Int64>("topic_numbers", 1000); 
  ros::Rate loop_rate(1);
//publishing to the "topic_numbers" at 1Hz with a queue size of 1000
  int count=0;
  while (ros::ok())
  {

    std_msgs::Int64 msg;
    msg.data = count+1;    
    ROS_INFO("%d", msg.data);
    chatter_pub.publish(msg);  //publish natural numbers, from 1
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }


  return 0;
}

