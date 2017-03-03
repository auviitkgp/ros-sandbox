#include <math.h> 
#include "ros/ros.h"

class Point
{
public:

  
  Point(double xpos, double ypos, double theta, ros::Time t);

  ~Point();

 
  double getAngle(Point* target);

  
  double getDistance(Point* target);

  double x;      
  double y;      
  ros::Time time;
  double angle;  
};
