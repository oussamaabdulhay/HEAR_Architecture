#include "HEAR_math/ButterFilter_2nd.hpp"

ButterFilter_2nd::ButterFilter_2nd(BF_settings t_settings) {
    this->_input_port_0 = new InputPort(ports_id::IP_0_DATA, this);
    this->_output_port = new OutputPort(ports_id::OP_0_DATA, this);
    _ports = {_input_port_0,_output_port};
    if (t_settings == BF_settings::FS120FC5) {
        _coeff_in_use = coeff_120Hz_2nd_butter_5hz;
    }
    else if(t_settings == BF_settings::FS200FC10) {
        _coeff_in_use = coeff_200Hz_2nd_butter;
    }
    else if (t_settings == BF_settings::FS200FC50) {
        _coeff_in_use = coeff_200Hz_2nd_butter_50hz;
    }
}

ButterFilter_2nd::~ButterFilter_2nd() {

}

void ButterFilter_2nd::runTask(DataMsg* t_msg) {
    float x=_ip_0;
	float y = -_coeff_in_use[0] * prev_y - _coeff_in_use[1] * prev2_y + _coeff_in_use[2] * x + _coeff_in_use[3] * prev_x + _coeff_in_use[4] * prev2_x;
    prev2_y = prev_y;
	prev_y = y;
	prev2_x = prev_x;
	prev_x = x;
    FloatMsg* x_msg = new FloatMsg();
    x_msg->data = y;
    this->_output_port->receiveMsgData(x_msg);
}

void ButterFilter_2nd::process(DataMsg* t_msg, Port* t_port) {
    
    if(t_port->getID() == ports_id::IP_0_DATA)
	{
        FloatMsg* float_msg = (FloatMsg*)t_msg;
        _ip_0 = float_msg->data;
        this->runTask(t_msg);
    }
}