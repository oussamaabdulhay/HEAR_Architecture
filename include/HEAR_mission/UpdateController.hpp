#pragma once
#include "HEAR_mission/MissionElement.hpp"
#include "HEAR_msg/ControllerMsg.hpp"
#include "HEAR_control/PID_values.hpp"
#include "HEAR_control/MRFT_values.hpp"
#include "HEAR_control/BB_values.hpp"

class UpdateController : public MissionElement {
private:
	Port* _output_port_0;
public:
    enum ports_id {OP_0};
    MRFT_parameters mrft_data;
	PID_parameters pid_data;
    BB_parameters bb_data;
	block_id target_block;
    void perform();
    void process(DataMsg* t_msg, Port* t_port) {};
    UpdateController();
    ~UpdateController();
};