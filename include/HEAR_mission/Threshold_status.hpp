#pragma once
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"
#include "HEAR_core/Block.hpp"
#include "HEAR_msg/Vector3DMsg.hpp"
#include "HEAR_msg/FloatMsg.hpp"

class Threshold_status : public Block {
private:
    Port* _input_port_0;
    Port* _input_port_1;
    Port* _output_port_0; 
    float threshold_position_t_h;
    float threshold_position_h_t;
    int window_size;
    float dt;
    float kf_data;
    int trigger_value;
    float old_value;
    FloatMsg trigger_msg;
    int counter; 
public:
    enum ports_id {IP_0_VS, IP_1_KF ,OP_0_HOV_TRACK};
    void process(DataMsg* t_msg, Port* t_port);
    void runTask(float);
    Threshold_status(float, float, int, float);
    ~Threshold_status();
};