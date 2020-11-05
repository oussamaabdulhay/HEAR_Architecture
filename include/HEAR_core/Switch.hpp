#pragma once
#include <functional>
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"
#include "HEAR_core/Block.hpp"
#include "HEAR_msg/FloatMsg.hpp"

class Switch : public Block{

private:
    std::function<bool(float,float)> _operation;
    float _trigger_value;
    Port* _input_port;
    Port* _trigger_port;
    Port* _output_port_0;
    Port* _output_port_1;
    Port* _active_output_port;

public:
    enum ports_id {IP_0_DATA, IP_1_TRIGGER, OP_0_DATA_DEFAULT, OP_1_DATA};
    void triggerCallback(float t_current_value);
    void process(DataMsg* t_msg, Port* t_port);
    Switch(std::function<bool(float,float)> t_operation, float t_trigger_value);
    ~Switch();
};