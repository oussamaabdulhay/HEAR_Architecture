#include "common_srv/InputPort.hpp"

InputPort::InputPort(int t_id, Block* t_block) : Port(t_id, t_block){
    this->_id = t_id;
    this->_block = t_block;
}

InputPort::~InputPort() {

}

void InputPort::receiveMsgData(DataMsg* t_msg){
    this->_block->process(t_msg, this);
}

void InputPort::receiveMsgData(DataMsg* t_msg, int channel_id){
    this->_block->process(t_msg, this);
}
