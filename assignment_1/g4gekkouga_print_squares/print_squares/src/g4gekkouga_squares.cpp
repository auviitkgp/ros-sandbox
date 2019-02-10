/*   Computes the square of the numbers published to topic_numbers and published them to another topic topic_squares  */

#include "ros/ros.h"
#include "std_msgs/Int64.h" //This is the type of message that is used for communation btw the nodes

ros::Publisher topic_Squares; // Made Global as to be used in callBack function also

void squareCalc(const std_msgs::Int64::ConstPtr& msgr) {
    
	ROS_INFO("Number Received : %d \n", msgr->data); // Msg received from topic_numbers and displayed in corresponding terminal
    
    std_msgs::Int64 msgp;
    msgp.data = (msgr->data)*(msgr->data); //new msg type var to store the computed square of the input
   
	topic_Squares.publish(msgp); // Publishing the computed square to topic_squares

/* Similarly here also the publishing rate is at 1Hz as the function is 
called at this rate and publishes at the same rate */

    ROS_INFO("Number Published : %d \n", msgp.data); // Msg Published to topic_squares and displayed in corresponding terminal
     
   }

 int main(int argc, char **argv) {
 
 	ros::init(argc, argv, "g4gekkouga_squares");
   
    ros::NodeHandle n; //access point for the communation with the system
  
    topic_Squares = n.advertise<std_msgs::Int64>("topic_squares", 1000); // Declared Globally and initializesd here to communicate with the ROS to publish to topic_squares

    ros::Subscriber topic_Numbers = n.subscribe<std_msgs::Int64>("topic_numbers", 1000, squareCalc); //

/*  There is no need for maintaing frequency manually as the publishing rate to topic_numbers is 1Hz ,
     the callBack function will also take input at the rate of 1Hz   */

  
    ros::spin(); // Required as there are callBacks as long as the _numbers node is publishing or Ctrl C is encountered
  
    return 0;
}