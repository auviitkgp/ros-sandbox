/*
includes all the necessary libraries required for common use. 
*/
#include "ros/ros.h"
#include "std_msgs/Int32.h"

int main(int argc,char **argv)
{
  ros::init(argc, argv, "numbers");
  //initializes the ros and name the node as amit-patil_numbers
  ros::NodeHandle n;
  //creates handle to the node   
  ros::Publisher num_pub = n.advertise<std_msgs::Int32>("topic_numbers", 100);//used for publishing messages on the topic ,'topic_numbers' of length upto 100
  ros::Rate loop_rate(1);//publishes messages at frequency at 1 Hz 
  int count = 1;//initialize counter
  std_msgs::Int32 message;//message is of int 32
  while (ros::ok())
  {       
    message.data = count;//message is equal to counter    
    num_pub.publish(message);//message is published to topic through num_pub
    ros::spinOnce();//processes callbacks
    loop_rate.sleep();//sleeps for the remainimg  time to get 1hz frequency
    ++count;//increment counter
  }
  return 0;
}
