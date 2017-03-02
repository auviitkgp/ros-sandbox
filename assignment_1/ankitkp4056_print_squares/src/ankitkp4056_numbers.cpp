#include "ros/ros.h"
#include "std_msgs/Int64.h"

using namespace std;

	/*
	* This node publishes integers on topic-"topic_numbers" starting from 1 at a frequency of 1 hz.
	*/

int main(int argc, char **argv)
{
  /*
	 * The ros::init() function is called before using any part of the ros system.
	 * The third argument here is the name of the node.
   */
  ros::init(argc, argv, "talker");

  /*
   * NodeHandle is the main access point to communications with the ROS system.

   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */

  ros::NodeHandle n;

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. 
   
   * This Tell the master that we are going to be publishing a message of type std_msgs/String on the topic "chatter". 
	 * The second argument is the size of our publishing queue. 
	 */


  ros::Publisher topic_numbers_pub = n.advertise<std_msgs::Int64>("topic_numbers", 1000);

	/*	
	 * ros::Rate allows us to specify a frequency with which we would like to run the loop.
	 */

  ros::Rate loop_rate(1);

  /**
   * A count of how many messages we have sent. 
   */

  int num = 1;
  while (ros::ok())
  {
    /**
     * This is the message object. 
     */

    std_msgs::Int64 msg;
    msg.data = num;

    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. 
     */
    topic_numbers_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
