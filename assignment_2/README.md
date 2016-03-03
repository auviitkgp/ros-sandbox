# Assignment 2

### Problem Statement

Write a `rosbuild` package that uses PID to maintain the heading of the vehicle.

### Topics Available

- Input: IMU
- Input: DVL
- Output: Thruster values in 6 thruster model

You must subscribe to the IMU topic (DVL also, if required) and calculate appropriate values for
each of the thrusters on the vehicle.

### Instructions

- You must use either the C++ or Python ROS API
- Code must be well documented (methods and modules should be documented)

### Logistics

- Clone this repository inside your `rosbuild` workspace
- `cd` into the `assignment_2` folder
- Switch to a new branch
- Use `roscreate-pkg` to create a package called `<username>_pid_control`
- `cd` into the package you just created, and change code there
- Run `rosmake` and make sure that it works before sending a PR
- You might need to have a working version of `kraken_3.0` codebase inside your `ros_workspace`
- You can include `kraken_msgs` in the list of dependencies, inside `manifest.xml` of your package

### Suggested Reading

- [Lecture, as a part of AI course on Udacity](https://www.youtube.com/watch?v=Ag8H3Iit9j4)
- [Wikipedia article](https://en.wikipedia.org/wiki/PID_controller)
