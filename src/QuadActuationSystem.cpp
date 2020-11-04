#include "HEAR_actuation/QuadActuationSystem.hpp"

QuadActuationSystem::QuadActuationSystem(std::vector<Actuator*> t_actuators) : ActuationSystem(t_actuators){
    _actuators = t_actuators;
    _input_port_0 = new InputPort(ports_id::IP_0_DATA_ROLL, this);
	_input_port_1 = new InputPort(ports_id::IP_1_DATA_PITCH, this);
	_input_port_2 = new InputPort(ports_id::IP_2_DATA_YAW, this);
	_input_port_3 = new InputPort(ports_id::IP_3_DATA_Z, this);
	_output_port_0 = new OutputPort(ports_id::OP_0_CMD, this);
    _output_port_1 = new OutputPort(ports_id::OP_1_ARM, this);
    _ports = {_input_port_0, _input_port_1, _input_port_2, _input_port_3, _output_port_0, _output_port_1};

}
QuadActuationSystem::~QuadActuationSystem() {

}

void QuadActuationSystem::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0_DATA_ROLL){
        FloatMsg* float_msg = (FloatMsg*)t_msg;
        _u[0] = float_msg->data;
    } 
    if(t_port->getID() == ports_id::IP_1_DATA_PITCH){
        FloatMsg* float_msg = (FloatMsg*)t_msg;
        _u[1] = float_msg->data;
        this->command();
    } 
    if(t_port->getID() == ports_id::IP_2_DATA_YAW){
        FloatMsg* float_msg = (FloatMsg*)t_msg;
        _u[2] = float_msg->data;
    } 
    if(t_port->getID() == ports_id::IP_3_DATA_Z){
        FloatMsg* float_msg = (FloatMsg*)t_msg;
        _u[3] = float_msg->data;
    } 
}

void QuadActuationSystem::command(){


    for(int i = 0; i < NUM_MOTORS; i++){
        _commands[i] = 0.0;
    }

    //Update pulse values
    for(int i = 0; i < NUM_MOTORS; i++){
        for(int j = 0; j < 4; j++){
            _commands[i] += _geometry[i][j] * _u[j];
        }
    }

    //Let's limit the PID output considering that a value of 0 is the minimum output and 1 is the maximum output. 
    //Thus, we have to adjust for the range 1150 to 2000 on _commands.
    //Normalize and Constrain

    for(int i = 0; i < NUM_MOTORS; i++){
        if(_armed){
            _commands[i] = (_commands[i] * (_escMax-_escMin_armed)) + _escMin_armed;
            _commands[i] = this->constrain(_commands[i], _escMin_armed, _escMax);
        }else{
            _commands[i] = _escMin;
        }
    }

    //Actuate
    for(int i = 0; i < NUM_MOTORS; i++){
        _actuators[i]->applyCommand(_commands[i]);
    }


    VectorDoubleMsg commands_msg;
    commands_msg.data = _commands;
    this->_output_port_0->receiveMsgData((DataMsg*)&commands_msg);
    // this->emitMsgUnicast((DataMsg*) &commands_msg, 
    //                             HexaActuationSystem::unicast_addresses::unicast_ActuationSystem_commands,
    //                             ROSUnit_BroadcastData::ros_broadcast_channels::actuation);

    BoolMsg armed_msg;
    armed_msg.data = _armed;
    this->_output_port_1->receiveMsgData((DataMsg*)&armed_msg);
    // this->emitMsgUnicast((DataMsg*) &armed_msg,
    //                             HexaActuationSystem::unicast_addresses::unicast_ActuationSystem_armed,
    //                             ROSUnit_BroadcastData::ros_broadcast_channels::armed);

}

int QuadActuationSystem::constrain(float value, int min_value, int max_value) {
    
    if (value > max_value) {
        value = max_value;
    } else if (value < min_value) {
        value = min_value;
    }

    return int(value);
}