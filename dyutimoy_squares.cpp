#include "ros/ros.h"
#include "std_msgs/Int64.h"

#include <stdio.h> 
#include<math.h>

#include <sstream>

void numCallback(const std_msgs::Int64::ConstPtr& num)
{
  std_msgs::Int64 squares;

  squares.data=num->data*num->data;

  ros::NodeHandle n1;

  ros::Publisher squares_sub= n1.advertise<std_msgs::Int64>("topic_squares",1000);

  ros::Rate loop_rate(1.0);
  while(ros::ok())
    {
      
      ROS_INFO ("squares_publish:[%ld]",squares.data);
      squares_sub.publish(squares);
      ros::spin();
      loop_rate.sleep();
    }
}

int main(int argc,char **argv)
{
  ros::init(argc,argv,"dyutimoy_squares");

  ros::NodeHandle n;
  
  ros::Subscriber squares_sub= n.subscribe("topic_number", 1000, numCallback);
 
  
 
  ros::spin();
  return 0; 

  
}
