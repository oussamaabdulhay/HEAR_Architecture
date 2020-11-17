#pragma once
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"
#include "HEAR_core/Block.hpp"
#include "HEAR_msg/FloatMsg.hpp"

class ConstantFloat : public Block {
private:
    float _val;
    Port* _input_port_0;
    Port* _input_port_1;
    Port* _output_port_0;
public:
    ConstantFloat(float);
    enum ports_id {IP_0_DATA, IP_1_TRIGGER, OP_0_DATA};
    void process(DataMsg* t_msg, Port* t_port);
    ~ConstantFloat();
};