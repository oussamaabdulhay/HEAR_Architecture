#pragma once
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"
#include "HEAR_core/Block.hpp"
#include "HEAR_msg/Vector3DMsg.hpp"
#include "HEAR_msg/FloatMsg.hpp"

class Threshold_status : public Block {
private:
    Port* _input_port_0;
    Port* _output_port_0; 
    float threshold_position_t_h;
    float threshold_position_h_t;
    float dt;
    int trigger_value;
    float old_value;
    FloatMsg trigger_msg; 
public:
    enum ports_id {IP_0 ,OP_0_HOV_TRACK};
    void process(DataMsg* t_msg, Port* t_port);
    void runTask(float);
    Threshold_status(float, float, float);
    ~Threshold_status();
};