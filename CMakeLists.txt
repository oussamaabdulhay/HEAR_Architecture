cmake_minimum_required(VERSION 2.8.3)
project(hear_architecture)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS
    roscpp
  DEPENDS
    system_lib
)

include_directories(
  include
  ${CMAKE_CURRENT_SOURCE_DIR}/libs/
  ${catkin_INCLUDE_DIRS}
)

FILE(GLOB SOURCE_FILES *.cpp
        src/*.cpp
        )

add_library(${PROJECT_NAME}
${SOURCE_FILES}
)

add_executable(${PROJECT_NAME}_node ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})
