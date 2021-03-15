#include "HEAR_math/SupressPeak.hpp"

SupressPeak::SupressPeak(float _threshold) {
    _input_port_0 = new InputPort(ports_id::IP_0_VEL, this);
    _output_port_0 = new OutputPort(ports_id::OP_VEL_THRESHOLDED, this);
    _ports = {_input_port_0, _output_port_0};

    peak_threshold = _threshold;
}

SupressPeak::~SupressPeak() {

}

void SupressPeak::process(DataMsg* t_msg, Port* t_port) {

    if(t_port->getID() == ports_id::IP_0_VEL){
        FloatMsg* float_msg = (FloatMsg*)t_msg;
        float velocity = float_msg->data;
        float abs_velocity = abs(velocity);

        if (abs_velocity > peak_threshold){
            FloatMsg vel_data;
            vel_data.data = 0;
            this->_output_port_0->receiveMsgData((DataMsg*) &vel_data);
        }

        else
        {
            FloatMsg vel_data;
            vel_data.data = velocity;
            this->_output_port_0->receiveMsgData((DataMsg*) &vel_data);
        }
    }
}

