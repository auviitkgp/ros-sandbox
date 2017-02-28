#include "ros/ros.h"
#include "std_msgs/Int64.h"

/**
 * This node subscribes to topic_numbers and will publish the squares of the numbers to another topic, topic_squares.
 */
void topic_numbersCallback(std_msgs::Int64 msg)
{
  ros::NodeHandle n;

  ros::Rate loop_rate(1);

  ros::Publisher topic_squares_pub = n.advertise<std_msgs::Int64>("topic_squares", 1000);

  msg.data=msg.data*msg.data;
  topic_squares_pub.publish(msg);
  loop_rate.sleep();
  ros::spinOnce();
}

int main(int argc, char **argv)
{
  /**
   *  ros::init() to be called before using any other
   * part of the ROS system.
   */

  ros::init(argc, argv, "squares");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */

  ros::NodeHandle n;

  /**
   * The subscribe() call is how you tell ROS that you want to receive messages on a given topic.  
   */

  ros::Subscriber sub = n.subscribe("topic_numbers", 1000, topic_numbersCallback);

  /**
   * ros::spin()will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
  ros::spin();

  return 0;
}
