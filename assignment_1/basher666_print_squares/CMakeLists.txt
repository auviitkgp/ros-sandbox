cmake_minimum_required(VERSION 2.8.3)
project(basher666_print_squares)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)


catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)


include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(basher666_numbers src/basher666_numbers.cpp)
target_link_libraries(basher666_numbers ${catkin_LIBRARIES})

add_executable(basher666_squares src/basher666_squares.cpp)
target_link_libraries(basher666_squares ${catkin_LIBRARIES})

add_executable(basher666_print src/basher666_print.cpp)
target_link_libraries(basher666_print ${catkin_LIBRARIES})
