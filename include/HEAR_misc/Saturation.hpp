#pragma once
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"
#include "HEAR_core/Block.hpp"
#include "HEAR_msg/FloatMsg.hpp"

class Saturation : public Block {
private:
    float _clip_value;
    Port* _input_port;
    Port* _output_port;
    float _input = 0.0;
public:
    void clip(float);
    enum ports_id {IP_0_DATA, OP_0_DATA};
    void process(DataMsg* t_msg, Port* t_port);
    Saturation(float);
    ~Saturation();
};