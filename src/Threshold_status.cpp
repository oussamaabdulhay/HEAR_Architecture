#include "HEAR_mission/Threshold_status.hpp"

Threshold_status::Threshold_status(float _threshold_pos,float _threshold_vel,float _dt ) {
    _input_port_0 = new InputPort(ports_id::IP_0, this);
    _output_port_0 = new OutputPort(ports_id::OP_0_HOV_TRACK, this);
    _ports = {_input_port_0, _output_port_0};

    threshold_position = _threshold_pos;
    threshold_velocity = _threshold_vel;
    dt = 1./_dt;
}

Threshold_status::~Threshold_status() {

}

void Threshold_status::process(DataMsg* t_msg, Port* t_port) {

    if(t_port->getID() == ports_id::IP_0){
        FloatMsg* float_msg = (FloatMsg*)t_msg;
        float data = float_msg->data;

        runTask(data);
        old_value = data;
     }
     

}

void Threshold_status::runTask(float position) {

    float relative_position; 
    relative_position = abs(position);
    

    float relative_velocity; 
    relative_velocity = abs(position - old_value)/dt;

        
    if(relative_position>threshold_position && relative_velocity>threshold_velocity)
    {
        if (trigger_msg.data!=2.5)
        {
        trigger_msg.data = 2.5;
        this->_output_port_0->receiveMsgData((DataMsg*) &trigger_msg);
        }
        
    }
    else if(relative_position<threshold_position && relative_velocity<threshold_velocity)
    {
        if (trigger_msg.data!=1)
        {
        trigger_msg.data = 1;
        this->_output_port_0->receiveMsgData((DataMsg*) &trigger_msg);
        }
    }
}