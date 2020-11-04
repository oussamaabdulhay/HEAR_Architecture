#pragma once
#include "HEAR_mission/MissionElement.hpp"
#include "HEAR_msg/MissionCommandMsg.hpp"
#include "HEAR_misc/common_types.hpp"

class MissionCommand : public MissionElement {

private:
    Port* _input_port_0;
    //TODO: refactor
    mission_command _command = mission_command::NULL_TYPE;
public:
    enum ports_id {IP_0};
    void process(DataMsg* t_msg, Port* t_port);
    void perform();
    MissionCommand();
    ~MissionCommand();
};