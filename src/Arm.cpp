#include "HEAR_mission/Arm.hpp"

Arm::Arm() {
    _output_port_0 = new OutputPort(ports_id::OP_0, this);
    _ports = {_output_port_0};
}

Arm::~Arm() {

}

void Arm::perform() {
    BoolMsg _arm_message;
    _arm_message.data = true;
    this->_output_port_0->receiveMsgData((DataMsg*)&_arm_message);
}