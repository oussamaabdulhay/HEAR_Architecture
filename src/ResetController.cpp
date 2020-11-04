
#include "HEAR_mission/ResetController.hpp"

ResetController::ResetController(){
    _output_port_0 = new OutputPort(ports_id::OP_0, this);
    _ports = {_output_port_0};
}
ResetController::~ResetController(){

}

void ResetController::perform(){
    ResetControllerMsg _reset_controller_msg;
    _reset_controller_msg.target_block=this->target_block;
    this->_output_port_0->receiveMsgData((DataMsg*)&_reset_controller_msg);
}
