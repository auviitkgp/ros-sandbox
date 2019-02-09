/*   Take the msg from topic_numbers and topic_squares and prints them accordingly  */

#include "ros/ros.h"
#include "std_msgs/Int64.h" ////This is the type of message that is used for communation btw the nodes


ros::Subscriber topic_Numbers ; // to suscribe to topic_numbers

ros::Subscriber topic_Squares ; // to suscribe to topic_numbers

void getSquare(const std_msgs::Int64::ConstPtr& msgr) {
     
    ROS_INFO("Received from topic_squares : %d \n", msgr->data); // as this fn is called when input received from topic_squares

    return ;

}

void getNum(const std_msgs::Int64::ConstPtr& msgr) {
   
    ROS_INFO("Received from topic_numbers : %d \n", msgr->data);  // as this fn is called when input received from topic_numbers

	return ;     
}

int main(int argc, char **argv){
 
	ros::init(argc, argv, "g4gekkouga_print");

	ros::NodeHandle n; //access point for the communation with the system
    

    topic_Numbers = n.subscribe("topic_numbers", 1000, getNum); // To receive msgs from topic_numbers

    topic_Squares = n.subscribe("topic_squares", 1000, getSquare); // To receive msgs from topic_squares
 	
    ros::spin(); //required as there are callBacks to the functions
  
    return 0;
}