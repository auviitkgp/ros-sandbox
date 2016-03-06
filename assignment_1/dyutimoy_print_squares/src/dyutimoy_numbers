#include "ros/ros.h"
#include "std_msgs/Int64.h"
#include <stdio.h>

#include <sstream>


int main(int argc,char ** argv)
{
  ros::init(argc,argv,"dyutimoy_numbers");
 
  ros::NodeHandle n;

  ros::Publisher number_pub= n.advertise<std_msgs::Int64>("topic_number",1000);
  //defining number_pub to  publish the numbers
  ros::Rate loop_rate(1.0);
  //specifying the rate
  int count = 0;
  
  while (ros::ok())
    {
      std_msgs::Int64 num;
      
      num.data=count++;
      
      ROS_INFO("number_publish:[%ld]",num.data);
      //printing the content to be published
      number_pub.publish(num);
      //publishing the number
      ros::spinOnce();
      
      loop_rate.sleep();

    }

  return 0;


}
