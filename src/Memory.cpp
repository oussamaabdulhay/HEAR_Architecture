#include "HEAR_core/Memory.hpp"

Memory::Memory() {
    this->_input_port = new InputPort(ports_id::IP_0_DATA, this);
    this->_trigger_port = new InputPort(ports_id::IP_1_TRIGGER, this);
    this->_output_port_0 = new OutputPort(ports_id::OP_0_DATA, this);
    _ports = {_input_port, _trigger_port, _output_port_0};
}

Memory::~Memory() {

}

void Memory::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0_DATA){
        if(_empty) {
            _past_val = ((FloatMsg*)t_msg)->data;
            _empty = false;
        }
    }else if(t_port->getID() == ports_id::IP_1_TRIGGER){
        FloatMsg t_floatmsg;
        t_floatmsg.data = _past_val;
        _output_port_0->receiveMsgData((DataMsg*)&t_floatmsg);
        _empty = true;
    }
}