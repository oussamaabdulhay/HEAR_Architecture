#include "HEAR_mission/DNNConfirmationCondition.hpp"

DNNConfirmationCondition::DNNConfirmationCondition(control_system t_cs){
    this->_input_port_0 = new InputPort(ports_id::IP_0, this);
    _ports = {_input_port_0};
    _cs = t_cs;
}

bool DNNConfirmationCondition::isConditionMet(){
	return _isConditionMet;
}

void DNNConfirmationCondition::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0) {
        IntegerMsg* int_msg = (IntegerMsg*)t_msg;
        int cs_data = int_msg->data;
        if(!_isConditionMet){
            _isConditionMet = (cs_data == (int)_cs);
        }
    }
}