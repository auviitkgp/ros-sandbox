#include "ros/ros.h"			
							//ros/ros.h is a convenience include that includes all the headers necessary to use the most common public pieces of the ROS system.
#include "std_msgs/Int32.h"
							//This includes the std_msgs/Int32 message, which resides in the std_msgs package. 
							//This is a header generated automatically from the Int32.msg file in that package.

#include <sstream>


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "sangeet259_numbers"); // Initiliase ROS. Specify the name of our node as sangeet259_numbers .

  
  ros::NodeHandle n; 		//Create a handle to this process' node. This will actually do the initialization of the node.

 
  ros::Publisher numbers_pub = n.advertise<std_msgs::Int32>("topic_numbers", 777); 
                           //Tell the master that we are going to be publish a message of type std_msgs/Int32 on the topic_numbers topic.
                           //777 is just the size of buffer nothing special about the number, by_the_way I am a MSD fan :) !
  ros::Rate loop_rate(1);  // It will send messages at the rate of 1Hz.

  
  int number = 1;          //Initilise the numbers to be sent , with 1 , obviously !
  while (ros::ok())        //Until ctrl+C is not pressed
  {

    std_msgs::Int32 num;   // create a Int32 type message object with name num to be sent as message across the topic.

    num.data = number;    //set the data attribute of our num message 'the number we want to send'
    number++;             //Increment the number by 1 in each loop.


    
    numbers_pub.publish(num); //Publish the number of the current loop to the topic "topic_numbers"

    ros::spinOnce();      //Need to call this funtion often to allow ROS process incoming messages

    loop_rate.sleep();    //Makes the loop to sleep for 1 second before publishing the next message !
  }

  return 0;
}