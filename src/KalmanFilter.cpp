#include "HEAR_math/KalmanFilter.hpp"

// KalmanFilter::KalmanFilter() {
//     _input_port_0 = new InputPort(ports_id::IP_0_ACC, this);
//     _input_port_1 = new InputPort(ports_id::IP_1_POS, this);
//     _output_port_0 = new OutputPort(ports_id::OP_0_VEL, this);
//     _ports = {_input_port_0, _input_port_1, _output_port_0};
    
//     x(2,0) = 9.81;
//     P(0,0) = 1;
//     P(1,1) = 1;
//     P(2,2) = 1;
// }

// KalmanFilter::~KalmanFilter() {

// }

// void KalmanFilter::process(DataMsg* t_msg, Port* t_port) {

// }