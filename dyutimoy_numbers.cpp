#include "ros/ros.h"
#include "std_msgs/Int64.h"
#include <stdio.h>

#include <sstream>


int main(int argc,char ** argv)
{
  ros::init(argc,argv,"dyutimoy_numbers");
 
  ros::NodeHandle n;

  ros::Publisher number_pub= n.advertise<std_msgs::Int64>("topic_number",1000);
  
  ros::Rate loop_rate(1.0);

  int count = 0;
  
  while (ros::ok())
    {
      std_msgs::Int64 num;
      
      num.data=count++;
      
      ROS_INFO("number_publish:[%ld]",num.data);
      
      number_pub.publish(num);
      
      ros::spinOnce();
      
      loop_rate.sleep();

    }

  return 0;


}
