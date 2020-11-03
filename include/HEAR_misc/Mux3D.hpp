#pragma once
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"
#include "HEAR_core/Block.hpp"
#include "HEAR_msg/Vector3DMsg.hpp"
#include "HEAR_msg/FloatMsg.hpp"

class Mux3D : public Block {
private:
    Port* _input_port_0;
    Port* _input_port_1;
    Port* _input_port_2;
    Port* _output_port;
    float _ip_0 = 0, _ip_1 = 0, _ip_2 = 0;
    Vector3DMsg mux3d_msg;
public:
    enum ports_id {IP_0_DATA, IP_1_DATA, IP_2_DATA, OP_0_DATA};
    void combine(DataMsg*);
    void process(DataMsg* t_msg, Port* t_port);
    Mux3D();
    ~Mux3D();
};