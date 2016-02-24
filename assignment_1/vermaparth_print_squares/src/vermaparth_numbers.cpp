#include "ros/ros.h"
#include <std_msgs/Int64.h>
#include "std_msgs/String.h"
#include <sstream>
#include <stdlib.h>

int main(int argc , char **argv)
{ 
  ros::init(argc ,argv, "number");
  
  ros::NodeHandle n1;
  
  ros::Publisher topic_numbers_pub = n1.advertise<std_msgs::Int64>("topic_numbers",1000);

  ros::Rate loop_rate(1);
  
  int num=1;

  while(ros::ok())
  {  
    std_msgs::Int64 msg;
   
    msg.data=num;

    ROS_INFO("%d",msg.data);

    topic_numbers_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();

    ++num;

  }
   
  return 0;
}
  
