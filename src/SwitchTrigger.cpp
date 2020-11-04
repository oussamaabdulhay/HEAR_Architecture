#include "HEAR_mission/SwitchTrigger.hpp"

void SwitchTrigger::perform() {
    _output_port_0->receiveMsgData((DataMsg*)&int_msg);
}

SwitchTrigger::SwitchTrigger() {
    _output_port_0 = new OutputPort(ports_id::OP_0, this);
    _ports = {_output_port_0};
}
SwitchTrigger::~SwitchTrigger(){
    
}