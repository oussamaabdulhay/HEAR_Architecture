#include "HEAR_misc/Demux3D.hpp"

Demux3D::Demux3D() {
    this->_input_port = new InputPort(ports_id::IP_0_DATA, this);
    this->_output_port_0 = new OutputPort(ports_id::OP_0_DATA, this);
    this->_output_port_1 = new OutputPort(ports_id::OP_1_DATA, this);
    this->_output_port_2 = new OutputPort(ports_id::OP_2_DATA, this);
    _ports = {_input_port, _output_port_0, _output_port_1, _output_port_2};
}

Demux3D::~Demux3D() {

}

void Demux3D::split_data(DataMsg* t_msg){
    _op_0_msg.data = _ip.x;
    this->_output_port_0->receiveMsgData(&_op_0_msg);
    _op_1_msg.data = _ip.y;
    this->_output_port_1->receiveMsgData(&_op_1_msg);
    _op_2_msg.data = _ip.z;
    this->_output_port_2->receiveMsgData(&_op_2_msg);
}

void Demux3D::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0_DATA){
        Vector3DMsg* v3d_msg = (Vector3DMsg*)t_msg;
        _ip = v3d_msg->data;
        this->split_data(t_msg);
    }
}