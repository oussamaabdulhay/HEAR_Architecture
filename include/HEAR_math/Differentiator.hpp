#pragma once
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"
#include "HEAR_core/Block.hpp"
#include "HEAR_core/Timer.hpp"
#include "HEAR_msg/FloatMsg.hpp"

class Differentiator : public Block {
private:
    float _prev = 0.0;
    Timer timer;
    float _dt;
    float diff;
    Port* _input_port;
    Port* _output_port;
public:
    Differentiator(float);
    enum ports_id {IP_0_DATA, OP_0_DATA};
    void process(DataMsg* t_msg, Port* t_port);
    ~Differentiator();
};