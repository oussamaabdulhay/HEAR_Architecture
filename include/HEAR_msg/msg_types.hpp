#pragma once
#include <stdint.h>

enum class msg_type {TESTMSG, SERIALDATA, reference, THREEAXISSENSORMSG, VELOCITY, 
                    ACCELERATION, THERMALIMAGE, optitrack, FLIGHTSCENARIO, POSES, TAGGEDPOSES, POSE, 
                    POSITION, ATTITUDE, HEADING, NOZZLEMSG, UPDATECONTROLLER, RESETCONTROLLER, 
                    control_system, HEARTBEAT, CONTROLLEROUTPUTMSG, UPDATEPOSEREFERENCE, UPDATENOZZLEPOSEREFERENCE, 
                    controller, float_msg, FLOAT, BOOLEAN, INTEGER, switcher, VECTOR2D, VECTOR3D, 
                    POINT, POINTS, VECTOR, external_reference, ack,internal_msg_start, ROS, EMPTY, 
                    VECTORDOUBLE, DOUBLE, FILTER_POINT, INT8,
                    RESTNORMREF_SETTINGS, IMU, SWITCHBLOCK, SWITCHOUT,                                                            //Flight Controller
                    arm_update, MISSIONCOMMAND, INFO, RestControllerMessage, MessageToBlock, ERROR, UAV_CONTROL_STATE};              //Flight Scenario
