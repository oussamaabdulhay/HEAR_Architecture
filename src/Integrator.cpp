#include "HEAR_math/Integrator.hpp"

Integrator::Integrator(float t_dt) {
    _dt = t_dt;
    _accum = 0.f;
    this->_input_port_0 = new InputPort(ports_id::IP_0_DATA, this);
    this->_input_port_1 = new InputPort(ports_id::IP_1_RESET, this);
    this->_output_port_0 = new OutputPort(ports_id::OP_0_DATA, this);
    _ports = {_input_port_0, _input_port_1, _output_port_0};
}

Integrator::~Integrator() {

}

void Integrator::process(DataMsg* t_msg, Port* t_port){
    if(t_port->getID() == ports_id::IP_0_DATA){
        _accum = _accum + ((FloatMsg*)t_msg)->data * _dt;
        FloatMsg AccumMsg;
        AccumMsg.data = _accum;
        this->_output_port_0->receiveMsgData((DataMsg*) &AccumMsg);
    }
    if(t_port->getID() == ports_id::IP_1_RESET){
        if(t_msg->getType() == msg_type::FLOAT) {
            reset(((FloatMsg*)t_msg)->data);
        }
        else if (t_msg->getType() == msg_type::EMPTY) {
            reset(0.f);
        }
    }
}

void Integrator::reset(float t_data) {
    _accum = t_data;
}