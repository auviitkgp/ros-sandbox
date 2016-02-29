#include "ros/ros.h"
#include "std_msgs/Int64.h"

#include <stdio.h> 
#include<math.h>

#include <sstream>

void numCallback(const std_msgs::Int64::ConstPtr& num)
{
  std_msgs::Int64 squares;

  squares.data=num->data*num->data;
  //finding squares

  ros::NodeHandle n1;

  ros::Publisher squares_pub= n1.advertise<std_msgs::Int64>("topic_squares",1000);
  // defining the publisher and the rate 
  ros::Rate loop_rate(1.0);
  while(ros::ok())
    {
      
      ROS_INFO ("squares_publish:[%ld]",squares.data);
      //printing the output to be published
      squares_pub.publish(squares);
      //publishing
      ros::spin();
      loop_rate.sleep();
    }
}

int main(int argc,char **argv)
{
  ros::init(argc,argv,"dyutimoy_squares");

  ros::NodeHandle n;
  
  ros::Subscriber squares_sub= n.subscribe("topic_number", 1000, numCallback);
  //susbscribing to topic_number
  
 
  ros::spin();
  return 0; 

  
}
