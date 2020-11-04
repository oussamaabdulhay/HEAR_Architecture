#include "HEAR_mission/MissionCommand.hpp"

MissionCommand::MissionCommand() {
    _input_port_0 = new InputPort(ports_id::IP_0, this);
    _ports = {_input_port_0};
}
MissionCommand::~MissionCommand() {
}
void MissionCommand::perform(){
    std::cout << "WAITING MISSION COMMAND" << std::endl;
    while(_command == mission_command::NULL_TYPE){
    }
    _command = mission_command::NULL_TYPE;
}
void MissionCommand::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0) {
        Int8Msg* command_msg = (Int8Msg*)t_msg;
        _command = static_cast<mission_command>(command_msg->data);
    }
}