
#include "HEAR_mission/ResetController.hpp"

ResetController::ResetController(){
    _output_port_0 = new OutputPort(ports_id::OP_0, this);
    _ports = {_output_port_0};
}
ResetController::~ResetController(){

}

void ResetController::perform(){
    Int8Msg _reset_controller_msg;
    _reset_controller_msg.data=(int8_t)this->target_block;
    this->_output_port_0->receiveMsgData((DataMsg*)&_reset_controller_msg);
}