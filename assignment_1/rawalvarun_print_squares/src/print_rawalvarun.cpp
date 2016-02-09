/********************************************************************************************************/
/* Include necessary header files ***********************************************************************/
/* ros/ros.h includes all the headers necessary to use the most common public pieces of the ROS system. */
/* std_msgs/Int64.h includes the std_msgs/Int64 message, which resides in the std_msgs package.**********/
/********************************************************************************************************/

#include "ros/ros.h"
#include "std_msgs/Int64.h"

void numberCallback(const std_msgs::Int64::ConstPtr& mssg)
   {
     ROS_INFO("Received number : [%ld]\n", mssg->data);
     // print out the numbers to the ROS output stream

   }

void squareCallback(const std_msgs::Int64::ConstPtr& mssg)
   {
     ROS_INFO("Received square : [%ld]\n", mssg->data);
     // print out the squares to the ROS output stream

   }

 int main(int argc, char **argv)
 {
 
   ros::init(argc, argv, "print");// Initialize the ROS, and name the node "print"
    
   ros::NodeHandle nod_Handl;// Create a handle to the node, responsible for initialization & cleanup of the node resources 

   ros::Subscriber number_subscribe = nod_Handl.subscribe<std_msgs::Int64>("topic_numbers", 1000,numberCallback);
   // subscribe to the incoming messages, through the created Subscriber 'number_subscribe' from the topic 'topic_numbers' 

 ros::Subscriber square_subscribe = nod_Handl.subscribe<std_msgs::Int64>("topic_squares", 1000,squareCallback);
   // subscribe to the incoming messages, through the created Subscriber 'square_subscribe' from the topic 'topic_squares' 
  
 ros::spin();// necessary here, as we're receiving callbacks
  
    return 0;
  }
