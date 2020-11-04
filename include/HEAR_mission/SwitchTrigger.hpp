#pragma once
#include "HEAR_mission/MissionElement.hpp"
#include "HEAR_msg/IntegerMsg.hpp"

class SwitchTrigger : public MissionElement{
private:
    Port* _output_port_0;
public:
    enum ports_id {OP_0};
    IntegerMsg int_msg;
    void perform();
    void process(DataMsg* t_msg, Port* t_port) {};
    SwitchTrigger();
    ~SwitchTrigger();
};