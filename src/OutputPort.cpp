#include "common_srv/OutputPort.hpp"

OutputPort::OutputPort(int t_id, Block* t_block) : Port(t_id, t_block){
    this->_id = t_id;
    this->_block = t_block;
}

OutputPort::~OutputPort() {

}

void OutputPort::receiveMsgData(DataMsg* t_msg){
    this->emitMsg(t_msg);
}