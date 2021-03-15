#pragma once
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"
#include "HEAR_core/Block.hpp"
#include "HEAR_msg/FloatMsg.hpp"

class SupressPeak : public Block {
private:
    Port* _input_port_0;
    Port* _output_port_0;
    float peak_threshold; 
public:
    enum ports_id {IP_0_VEL, OP_VEL_THRESHOLDED};
    void process(DataMsg* t_msg, Port* t_port);
    SupressPeak(float);
    ~SupressPeak();
};