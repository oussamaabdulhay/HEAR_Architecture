#pragma once

#include "HEAR_msg/Vector3DMsg.hpp"
#include "HEAR_msg/FloatMsg.hpp"
#include "HEAR_msg/RestrictedNormRefSettingsMsg.hpp"
#include "HEAR_msg/PosesMsg.hpp"
#include "HEAR_nav/Waypoint.hpp"
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"

class RestrictedNormWaypointRefGenerator : public Block{
private:
    std::vector<Waypoint> Waypoints;
    double max_norm = 0.2;
    bool enabled=false;
    int old_size = 0;
    Port* _input_port_0;
    Port* _input_port_1;
    Port* _input_port_2;
    Port* _output_port_0;
    Port* _output_port_1;
    Port* _output_port_2;
    Port* _output_port_3;
    Port* _output_port_4;
    void updateControlSystemsReferences(Vector3D<double> position,double yaw);
public:
    enum ports_id {IP_0_WAYPOINT, IP_1_SETTINGS, IP_2_DATA, OP_0_X, OP_1_Y, OP_2_Z, OP_3_YAW, OP_4_COUNTER};
    void process(DataMsg* t_msg, Port* t_port);
    RestrictedNormWaypointRefGenerator();
};