cmake_minimum_required(VERSION 2.8.3)
project(hear_architecture)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  message_generation
  genmsg
)

add_message_files(
  FILES
  Pose.msg
  Poses.msg
  Point2D.msg
)

add_service_files(
   FILES
   get_float.srv
   get_poses.srv
   set_float.srv
   set_int.srv
   set_point.srv
   set_points.srv
   set_pose.srv
   set_poses.srv
   set_vector.srv
) 

generate_messages(
   DEPENDENCIES
   std_msgs
   geometry_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS
    roscpp
    std_msgs
  DEPENDS
    system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

FILE(GLOB SOURCE_FILES *.cpp
        src/*.cpp
        )

add_library(${PROJECT_NAME}
  ${SOURCE_FILES}
)

target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

# install(
#   TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
# )

# install(
#   DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
# )