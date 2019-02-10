cmake_minimum_required(VERSION 2.8.3)
project(print_squares)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES print_squares
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(g4gekkouga_numbers src/g4gekkouga_numbers.cpp)
target_link_libraries(g4gekkouga_numbers ${catkin_LIBRARIES})
add_dependencies(g4gekkouga_numbers beginner_tutorials_generate_messages_cpp)

add_executable(g4gekkouga_squares src/g4gekkouga_squares.cpp)
target_link_libraries(g4gekkouga_squares ${catkin_LIBRARIES})
add_dependencies(g4gekkouga_squares beginner_tutorials_generate_messages_cpp)

add_executable(g4gekkouga_print src/g4gekkouga_print.cpp)
target_link_libraries(g4gekkouga_print ${catkin_LIBRARIES})
add_dependencies(g4gekkouga_print beginner_tutorials_generate_messages_cpp)
