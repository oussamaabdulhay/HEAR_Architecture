#include "HEAR_mission/Threshold_status.hpp"

Threshold_status::Threshold_status(float _threshold_pos_1,float _threshold_pos_2, float _threshold_pos_3, float _dt ) {
    _input_port_0 = new InputPort(ports_id::IP_0_VS, this);
    _input_port_1 = new InputPort(ports_id::IP_1_KF, this);
    _output_port_0 = new OutputPort(ports_id::OP_0_HOV_TRACK, this);
    _ports = {_input_port_0, _input_port_1, _output_port_0};

    threshold_position_h_t = _threshold_pos_1;
    threshold_position_t_h = _threshold_pos_2;
    kalman_filter_error = _threshold_pos_3;
    dt = 1./_dt;
}

Threshold_status::~Threshold_status() {

}

void Threshold_status::process(DataMsg* t_msg, Port* t_port) {

    if(t_port->getID() == ports_id::IP_0_VS){
        FloatMsg* float_msg = (FloatMsg*)t_msg;
        float data = float_msg->data;

        runTask(data);
        old_value = data;
     }
    else if(t_port->getID() == ports_id::IP_1_KF){
        FloatMsg* float_msg = (FloatMsg*)t_msg;
        kf_data = float_msg->data;
     }
     

}

void Threshold_status::runTask(float position) {

    float relative_position; 
    relative_position = position;
    

    float relative_velocity; 
    relative_velocity = abs(position - old_value)/dt;

        
    if(abs(relative_position) > threshold_position_h_t)
    {
        if (trigger_msg.data!=2.5)
        {
        trigger_msg.data = 2.5;
        this->_output_port_0->receiveMsgData((DataMsg*) &trigger_msg);
        }
        
    }
    else if(abs(relative_position - kf_data) < kalman_filter_error && abs(relative_position)<threshold_position_t_h )
    {
        if (trigger_msg.data!=1)
        {
        trigger_msg.data = 1;
        this->_output_port_0->receiveMsgData((DataMsg*) &trigger_msg);
        }
    }
}