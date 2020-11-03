#pragma once
#include "cmath"
#include "HEAR_math/RotationMatrix3by3.hpp"
#include "HEAR_msg/Vector3DMsg.hpp"
#include "HEAR_msg/FloatMsg.hpp"
#include "HEAR_core/Block.hpp"
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"

class Transform_InertialToBody : public Block {
private:
    static float  _inertial_command_x;
    static float  _inertial_command_y;
    static float  _inertial_command_z;
    bool _opti_x_received = false, _opti_y_received = false, _current_yaw_received = false;
    RotationMatrix3by3 _rotation_matrix;
    Port* _input_port_0;
    Port* _input_port_1;
    Port* _input_port_2;
    Port* _output_port_0;
    Port* _output_port_1;
public:
    enum ports_id {IP_0_X, IP_1_Y, IP_2_YAW, OP_0_DATA, OP_1_DATA};
    void process(DataMsg* t_msg, Port* t_port);
    Transform_InertialToBody();
    ~Transform_InertialToBody();
};