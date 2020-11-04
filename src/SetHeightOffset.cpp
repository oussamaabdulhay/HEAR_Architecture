#include "HEAR_mission/SetHeightOffset.hpp"

SetHeightOffset::SetHeightOffset() {
    _input_port_0 = new InputPort(ports_id::IP_0, this);
    _output_port_0 = new OutputPort(ports_id::OP_0, this);
    _ports = {_input_port_0, _output_port_0};
}

SetHeightOffset::~SetHeightOffset() {

}

void SetHeightOffset::perform(){
    FloatMsg float_msg;
    float_msg.data = _current_z;
    this->_output_port_0->receiveMsgData(&float_msg);
}

void SetHeightOffset::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0) {
        _current_z = ((Vector3DMsg*) t_msg)->data.z;
    }
}