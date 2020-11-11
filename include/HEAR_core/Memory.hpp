#pragma once

#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"
#include "HEAR_core/Block.hpp"
#include "HEAR_msg/FloatMsg.hpp"

class Memory : public Block{

private:

    bool _empty;
    float _past_val;
    Port* _input_port;
    Port* _trigger_port;
    Port* _output_port_0;

public:
    enum ports_id {IP_0_DATA, IP_1_TRIGGER, OP_0_DATA};
    void process(DataMsg* t_msg, Port* t_port);
    Memory();
    ~Memory();
};