#pragma once
#include "HEAR_msg/PosesMsg.hpp"
#include "HEAR_mission/MissionElement.hpp"
#include "HEAR_msg/Vector3DMsg.hpp"

class SetRelativeWaypoint : public MissionElement{
private:
    Port* _input_port_0;
    Port* _input_port_1;
    Port* _output_port_0;
    float _waypoint_x, _waypoint_y, _waypoint_z, _waypoint_yaw;
    float _current_x, _current_y, _current_z, _current_yaw;
public:
    enum ports_id {IP_0, IP_1, OP_0};
    void process(DataMsg* t_msg, Port* t_port);
    void perform();
    SetRelativeWaypoint(float, float, float, float);
    ~SetRelativeWaypoint();
};