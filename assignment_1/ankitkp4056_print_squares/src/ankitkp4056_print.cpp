#include "ros/ros.h"
#include "std_msgs/Int64.h"

/**
 * This node subscribes to topic_numbers and topic_squares and will output them using ROS_INFO.
 * The below Callback funcs will print the output using ROS_INFO.
 */

void numCallback(std_msgs::Int64 msg)
{
	ROS_INFO("numbers: [%d]", msg.data);
  }

void sqCallback(std_msgs::Int64 msg)
{
	ROS_INFO("squares: [%d]", msg.data);
  }

int main(int argc, char **argv,)
{
  /**
   *  ros::init() to be called before using any other
   * part of the ROS system.
   */

  ros::init(argc, argv, "print");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */

  ros::NodeHandle n;
  ros::Rate loop_rate(1);

  /**
   * The subscribe() call is how you tell ROS that you want to receive messages on a given topic.  
   */

  ros::Subscriber sub1 = n.subscribe("topic_numbers", 1000, numCallback);
  loop_rate.sleep();
  ros::Subscriber sub1 = n.subscribe("topic_squares", 1000, numCallback);

  /**
   * ros::spin()will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
  ros::spin();

  return 0;
}
