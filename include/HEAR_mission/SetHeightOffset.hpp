#pragma once
#include "HEAR_mission/MissionElement.hpp"
#include "HEAR_msg/PositionMsg.hpp"
#include "HEAR_msg/FloatMsg.hpp"

class SetHeightOffset : public MissionElement {
private:
    Port* _input_port_0;
    Port* _output_port_0;
	float _current_z;
public:
    enum ports_id {IP_0, OP_0};
    void process(DataMsg* t_msg, Port* t_port);
    void perform();
    SetHeightOffset();
    ~SetHeightOffset();
};
