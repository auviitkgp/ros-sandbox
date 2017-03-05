#include "header.h"
#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/Twist.h"
#include <queue>

class NodePID
{
public:

  
  NodePID(ros::Publisher pub, double tol, double tolA, double dist, double ang, double mSpeed, double mASpeed);

  ~NodePID();

  
  void publishMessage(double angleCommand, double speedCommand);

 /* This method reads data from sensor and processes them to variables.
   */
      
  void messageCallback(const nav_msgs::Odometry::ConstPtr& msg);

  /*if robot is close enough from target point, target is accomplished and method returns true.
   */
  bool closeEnough(Point* actual);

  /* This method calculates action intervention from PSD controller.
   */
  double calculatePSD(Point* actual, double actualValue, double lastValue, double reference, double kP, double kD, double kS, double *sum);

//variables
  Point *start;     // Start position. Distance will be measured from here
  Point *last;      // Last position of robot.
  double tolerance;   // Tolerated deviation from target distance.
  double maxSpeed;    // Maximal velocity.
  double maxASpeed;   // Maximal angular velocity.
  ros::Publisher pubMessage; // Object for publishing messages.
  double targetDistance; // Robot will go forward this distance.
  double targetAngle;    // Robot will turn by this angle.
  int iterations;        // Number of received messages.
  double sumDistance;    // Sum of distance errors for PSD controller.
  double sumAngle;       // Sum of angle errors for PSD controller.
  double toleranceAngle; // Tolerated deviation from target angle.
};
