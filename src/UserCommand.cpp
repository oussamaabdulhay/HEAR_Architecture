#include "HEAR_mission/UserCommand.hpp"

UserCommand::UserCommand() {
    _input_port_0 = new InputPort(ports_id::IP_0, this);
    _ports = {_input_port_0};
}
UserCommand::~UserCommand() {
}
void UserCommand::perform(){
    std::cout << "WAITING USER COMMAND" << std::endl;
    while(_command == user_command::NULL_TYPE){
    }
    _command = user_command::NULL_TYPE;
}
void UserCommand::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0) {
        Int8Msg* command_msg = (Int8Msg*)t_msg;
        _command = static_cast<user_command>(command_msg->data);
    }
}