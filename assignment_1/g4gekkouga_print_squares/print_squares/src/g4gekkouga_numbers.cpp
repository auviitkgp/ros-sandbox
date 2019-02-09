/*   Publisher Node to Publish numbers from 1 onwards to the topic topic_numbers  */

#include "ros/ros.h"
#include "std_msgs/Int64.h"  //This is the type of message that is used for communation btw the nodes

int main(int argc, char **argv) {

	ros::init(argc, argv, "g4gekkouga_numbers"); //

	ros::NodeHandle n; //access point for the communation with the system

	ros::Publisher topic_Numbers = n.advertise<std_msgs::Int64>("topic_numbers", 1000); // Now topic_Numbers can be used to communicate with the ROS to publish to topic_numbers 

	ros::Rate loop_rate(1); // Setting the number generation rate to 1HZ

	int count = 0;
	
	while (ros::ok()) {	 // returns false on ctrl C in the console

		count++;  //Starting from 1 and all following numbers
		
		std_msgs::Int64 msg;  // For publishing to the topic
		msg.data = count;

		topic_Numbers.publish(msg);  // Publish the message to topic topic_numbers

		ROS_INFO("Number Published : %d", msg.data); // Displays the number published to the topic in the correspoing console of this node 

		loop_rate.sleep(); // To maintain the 1Hz Frequency rate
	}

	return 0;
}



