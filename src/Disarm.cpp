#include "HEAR_mission/Disarm.hpp"

Disarm::Disarm(){
    _output_port_0 = new OutputPort(ports_id::OP_0, this);
    _ports = {_output_port_0};
}
Disarm::~Disarm(){
    
}
void Disarm::perform(){
    BoolMsg _arm_message;
    _arm_message.data = false;
    this->_output_port_0->receiveMsgData((DataMsg*)&_arm_message);
}