/********************************************************************************************************/
/* Include necessary header files ***********************************************************************/
/* ros/ros.h includes all the headers necessary to use the most common public pieces of the ROS system. */
/* std_msgs/Int64.h includes the std_msgs/Int64 message, which resides in the std_msgs package.**********/
/********************************************************************************************************/

#include "ros/ros.h"
#include "std_msgs/Int64.h"

 int main(int argc, char **argv)
 {
 
   ros::init(argc, argv, "numbers");// Initialize the ROS, and name the node "numbers"
    
   ros::NodeHandle nod_Handl;// Create a handle to the node, responsible for initialization & cleanup of the node resources

   ros::Publisher number_publish = nod_Handl.advertise<std_msgs::Int64>("topic_numbers", 1000);
   // We'll be publishing messages of Int64 type onto the topic "topic_numbers",with message queue size upto 1000
   
   ros::Rate loop_rate(1);// We want to publish number messages at a frequency of 1 Hz
 
   int count = 0;// initializing count to ZERO
   std_msgs::Int64 mssg;// creating a message variable mssg

   while (ros::ok())// while ROS system is running fine
    {         
      mssg.data = ++count;// generate numbers starting from 1
   
      ROS_INFO("Published number : [%ld]\n", mssg.data);// print out the numbers to the ROS output stream
   
      number_publish.publish(mssg);// publish the message, through the created Publisher 'number_publish' to the topic 'topic_numbers' 
  
      ros::spinOnce();// actually not necessary here, as we're not receiving any callbacks
  
      loop_rate.sleep();// use the ros::Rate object to sleep for the time remaining to let us hit our 1 Hz publish rate
    }
  
    return 0;
  }
