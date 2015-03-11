#include "ros/ros.h"
 #include "std_msgs/String.h"
 #include <string> 
#include <stdlib.h> 
 void chatterCall2(const std_msgs::String::ConstPtr& msg2)
 { ROS_INFO("square= %s", msg2->data.c_str()); } 
void chatterCallback(const std_msgs::String::ConstPtr& msg)
 { ROS_INFO("required number= %s", msg->data.c_str()); }

int main(int argc, char **argv) 
{ ros::init(argc, argv, "print");
 ros::NodeHandle n; 
 ros::Rate loop_rate(1);
ros::Subscriber sub2 = n.subscribe("topic_squares", 1000, chatterCall2);
loop_rate.sleep();
 ros::Subscriber sub = n.subscribe("topic_numbers", 1000, chatterCallback);
 ros::spin(); 
return 0;
 }


