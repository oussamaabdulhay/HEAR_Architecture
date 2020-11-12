#pragma once
#include "HEAR_mission/MissionElement.hpp"
#include "HEAR_msg/Int8Msg.hpp"
#include "HEAR_core/common_types.hpp"

class UserCommand : public MissionElement { // Note: was MissionCommand

private:
    Port* _input_port_0;
    //TODO: refactor
    user_command _command = user_command::NULL_TYPE;
public:
    enum ports_id {IP_0};
    void process(DataMsg* t_msg, Port* t_port);
    void perform();
    UserCommand();
    ~UserCommand();
};
