#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
int main(int argc, char **argv)
{ 
  ros::init(argc, argv, "numbers_aranyadan");  
  ros::NodeHandle n; 
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("topic_numbers", 1000);
  ros::Rate loop_rate(1); 
  int count = 0;
  while (ros::ok())
  {    
    std_msgs::String msg;
    std::stringstream ss;
    ss << count;
    msg.data = ss.str();   
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
  return 0;
}