#pragma once
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"
#include "HEAR_core/Block.hpp"
#include "HEAR_msg/Vector3DMsg.hpp"
#include "HEAR_msg/FloatMsg.hpp"

class Demux3D : public Block{
private:
    Port* _input_port;
    Port* _output_port_0;
    Port* _output_port_1;
    Port* _output_port_2;
    FloatMsg _op_0_msg, _op_1_msg, _op_2_msg;
    Vector3D<float> _ip;
public:
    enum ports_id {IP_0_DATA, OP_0_DATA, OP_1_DATA, OP_2_DATA};
    void split_data(DataMsg*);
    void process(DataMsg* t_msg, Port* t_port);
    Demux3D();
    ~Demux3D();
};