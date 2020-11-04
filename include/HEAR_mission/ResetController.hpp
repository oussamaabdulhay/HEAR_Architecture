#pragma once
#include "HEAR_mission/MissionElement.hpp"
#include "HEAR_msg/Int8Msg.hpp"

class ResetController : public MissionElement {
private:
	Port* _output_port_0;
public:
    enum ports_id {OP_0};
    void process(DataMsg* t_msg, Port* t_port) {};
	block_id target_block;
    void perform();
    ResetController();
    ~ResetController();
};