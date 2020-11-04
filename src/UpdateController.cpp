#include "HEAR_mission/UpdateController.hpp"

void UpdateController::perform(){
    ControllerMsg _controller_parameters_message;
    //TODO refactor, remove id from PIDData and send separately
    _controller_parameters_message.pid_param = this->pid_data;
    _controller_parameters_message.mrft_param = this->mrft_data;
    _controller_parameters_message.bb_param = this->bb_data;
    _output_port_0->receiveMsgData((DataMsg*)&_controller_parameters_message);
}

UpdateController::UpdateController(){
    _output_port_0 = new OutputPort(ports_id::OP_0, this);
    _ports = {_output_port_0};
}
UpdateController::~UpdateController(){

}