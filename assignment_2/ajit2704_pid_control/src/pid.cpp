#include "header.h"
#include "node.h"

#define SUBSCRIBER_SIZE 1  // Size of buffer for subscriber.
#define PUBLISHER_SIZE 1000  // Size of buffer for publisher.
#define TOLERANCE 0.01  //at which the distance will be considered as achieved.
#define TOLERANCE_ANGLE 0.02  // Differenc from target angle, which will be tolerated.
#define MAX_SPEED 0.5    // Maximum speed of robot.
#define MAX_A_SPEED 2.0    // Maximum angular speed of robot.
#define PUBLISHER_TOPIC "/cmd_vel"
#define SUBSCRIBER_TOPIC "odom"
#define PI 3.141592

int main(int argc, char **argv)
{
  //Initialization of node
  ros::init(argc, argv, "pid");
  ros::NodeHandle n;

  
   
  //Creating publisher
  ros::Publisher pubMessage = n.advertise<geometry_msgs::Twist>(PUBLISHER_TOPIC, PUBLISHER_BUFFER_SIZE);

  //Creating object, which stores data from sensors and has methods for
  //publishing and subscribing
  NodePID *nodePID = new NodePID(pubMessage, TOLERANCE, TOLERANCE_ANGLE, distance, angle, MAX_SPEED, MAX_A_SPEED);

  //Creating subscriber 
  ros::Subscriber sub = n.subscribe(SUBSCRIBER_TOPIC, SUBSCRIBER_BUFFER_SIZE, &NodePID::messageCallback, nodePID);
  ros::spin();

  return 0;
}
