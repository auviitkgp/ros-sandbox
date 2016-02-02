/*
includes all the necessary libraries required for common use. 
*/
#include "ros/ros.h"
#include "std_msgs/Int32.h"

void numbersCallback(const std_msgs::Int32::ConstPtr& message)
{
  ROS_INFO("topic_numbers output: [%d]", message->data);
}
//output by topic_number
void squaresCallback(const std_msgs::Int32::ConstPtr& message)
{
  ROS_INFO("topic_squares output: [%d]", message->data);
}
//output by topic_squares
int main(int argc, char **argv)
{
  ros::init(argc, argv, "amit-patil_print");// initialize ros and node named amit-patil_print
  ros::NodeHandle hdl;//handle is created for node   
  ros::Subscriber sub_numbers = hdl.subscribe("/topic_numbers", 100, numbersCallback);//subscribes to topic 'topic_numbers' 
  ros::Subscriber sub_squares = hdl.subscribe("/topic_squares", 100, squaresCallback);//subscribes to topic 'topic_squares'   
  ros::spin();

  return 0;
}
