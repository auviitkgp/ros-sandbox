#include "ros/ros.h"
                      //ros/ros.h is a convenience include that includes all the headers necessary to use the most common public pieces of the ROS system.
#include "std_msgs/Int32.h"
                      //This includes the std_msgs/Int32 message, which resides in the std_msgs package. 
                      //This is a header generated automatically from the Int32.msg file in that package.

  void callback_topic_numbers(const std_msgs::Int32::ConstPtr& num)    
  						        //callback function for topic_numbers
    {
  	ROS_INFO("topic_numbers : [%d]\n ",num->data);
                      //ROS_INFO is a kind of printf function equivalent to stdout/stderr, prints the number in the terminal
    }

  void callback_topic_squares(const std_msgs::Int32::ConstPtr& square)    
  						        //callback function for topic_squares
    {
  	ROS_INFO("topic_squares : [%d]\n",square->data);
                      //ROS_INFO is a kind of printf function equivalent to stdout/stderr, prints the square in the terminal
    }


  int main(int argc,char **argv)
  {
  	ros::init(argc, argv, "sangeet259_print"); 
                      // Initiliase ROS. Specify the name of our node as sangeet259_print
  	ros::NodeHandle N1, N2;                   
                      //Create two nodes for this process handle to handle two subscriptions
	  ros::Rate loop_rate(1);
                      //1 Hertz
  	ros::Subscriber sub1 = N1.subscribe("topic_numbers", 777, callback_topic_numbers);
                      //Subscribes to the topic "topic_numbers" and calls the callback function "callback_topic_numbers" whenever a new message arrives.
  	loop_rate.sleep();
  	ros::Subscriber sub2 = N2.subscribe("topic_squares", 777, callback_topic_squares);
                      //Subscribes to the topic "topic_squares" and calls the callback function "callback_topic_squares" whenever a new message arrives.
  	ros::spin();
  	return 0;
  }