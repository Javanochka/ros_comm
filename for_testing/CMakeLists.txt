cmake_minimum_required(VERSION 2.8.3)
project(for_testing)

find_package(catkin REQUIRED COMPONENTS
  rosbag
  roscpp
  std_msgs
)

catkin_package(
  LIBRARIES for_testing
  CATKIN_DEPENDS rosbag roscpp
)


include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(talker1 src/talker1.cpp)
target_link_libraries(talker1 ${catkin_LIBRARIES})

add_executable(talker2 src/talker2.cpp)
target_link_libraries(talker2 ${catkin_LIBRARIES})
