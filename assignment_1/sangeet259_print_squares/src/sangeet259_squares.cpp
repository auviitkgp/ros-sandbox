#include "ros/ros.h"
					//ros/ros.h is a convenience include that includes all the headers necessary to use the most common public pieces of the ROS system.
#include "std_msgs/Int32.h"
				//This includes the std_msgs/Int32 message, which resides in the std_msgs package. 
				//This is a header generated automatically from the Int32.msg file in that package.

void topic_numbers_Callback(const std_msgs::Int32::ConstPtr& msg)
{
	int n;
	ros::NodeHandle sq1;   			// Created our first handle for this Node
	ros::Publisher square_pub = sq1.advertise<std_msgs::Int32>("topic_squares", 777);  
									//Advertise to master that we are going to publish to a topic "topic_squares" .
	n = msg->data;        			//set the data part of msg to be equal to n . 
	std_msgs::Int32 square;			//created a "square" object of std_msgs/Int32.
	square.data = n*n;				//set the data in square as square of n.
	square_pub.publish(square);		// Now, publish the square on the topic "topic_squares".
	ros::spin();					
}
	

int main(int argc, char **argv)
{
	ros::init(argc, argv, "sangeet259_squares");	
									// Initiliase ROS. Specify the name of our node as sangeet259_squares
	ros::NodeHandle sq2;			//This creates a second handle for this process' node
	ros::Subscriber sub = sq2.subscribe("topic_numbers", 777, topic_numbers_Callback);
									//Subscribes to the topic "topic_numbers" and calls the callback function "topic_numbers_Callback" whenever a new message arrives.

	ros::spin();// As you are receiving callbacks, 
				// therfore  if you were to add a subscription into this application, and did not have ros::spinOnce() here, your callbacks would never get called
	return 0;
}