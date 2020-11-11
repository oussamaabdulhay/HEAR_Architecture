#pragma once
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"
#include "HEAR_core/Block.hpp"
#include "HEAR_msg/FloatMsg.hpp"

class Integrator : public Block {
private:
    float _accum;
    float _dt;
    Port* _input_port_0;
    Port* _input_port_1;
    Port* _output_port_0;
public:
    Integrator(float);
    enum ports_id {IP_0_DATA, IP_1_RESET, OP_0_DATA};
    void process(DataMsg* t_msg, Port* t_port);
    void reset(float);
    ~Integrator();
};