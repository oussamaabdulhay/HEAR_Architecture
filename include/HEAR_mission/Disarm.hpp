#pragma once
#include "HEAR_mission/MissionElement.hpp"
#include "HEAR_msg/BoolMsg.hpp"
#include "HEAR_mission/Arm.hpp"

class Disarm : public MissionElement {
private:
    Port* _output_port_0;
public:
    enum ports_id {OP_0};
    void process(DataMsg* t_msg, Port* t_port) {};
    void perform();
    Disarm();
    ~Disarm();
};