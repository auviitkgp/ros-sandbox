/********************************************************************************************************/
/* Include necessary header files ***********************************************************************/
/* ros/ros.h includes all the headers necessary to use the most common public pieces of the ROS system. */
/* std_msgs/Int64.h includes the std_msgs/Int64 message, which resides in the std_msgs package.**********/
/********************************************************************************************************/

#include "ros/ros.h"
#include "std_msgs/Int64.h"

   ros::Publisher square_publish;

void numberCallback(const std_msgs::Int64::ConstPtr& mssg)
   {
     std_msgs::Int64 square_mssg;// creating a message variable square_mssg
     square_mssg.data = (mssg->data)*(mssg->data);
     ROS_INFO("Received number : [%ld]\n", mssg->data);
     // print out the numbers to the ROS output stream

     square_publish.publish(square_mssg);
     // publish the message, through the created Publisher 'square_publish' to the topic 'topic_squares' 

     ROS_INFO("Published number : [%ld]\n", square_mssg.data);
     // print out the squares to the ROS output stream
   }

 int main(int argc, char **argv)
 {
 
   ros::init(argc, argv, "squares");// Initialize the ROS, and name the node "squares"

   ros::NodeHandle nod_Handl;// Create a handle to the node, responsible for initialization & cleanup of the node resources 

   square_publish = nod_Handl.advertise<std_msgs::Int64>("topic_squares", 1000);
  // We'll be publishing messages of Int64 type onto the topic "topic_squares",with message queue size upto 1000

   ros::Subscriber number_subscribe = nod_Handl.subscribe<std_msgs::Int64>("topic_numbers", 1, numberCallback);
   // subscribe to the incoming messages, through the created Subscriber 'number_subscribe' from the topic 'topic_numbers' 
  
   ros::spin();// necessary here, as we're receiving callbacks
  
    return 0;
  }
