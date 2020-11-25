#include "HEAR_math/KalmanFilter.hpp"

KalmanFilter::KalmanFilter(float t_u_scale) {
    _input_port_0 = new InputPort(ports_id::IP_0_ACC, this);
    _input_port_1 = new InputPort(ports_id::IP_1_POS, this);
    _output_port_0 = new OutputPort(ports_id::OP_0_VEL, this);
    _ports = {_input_port_0, _input_port_1, _output_port_0};
    
    _x << 0,
          0,
          9.81;
    _P << 1, 0, 0,
         0, 1, 0,
         0, 0, 1;
    _F << 1, _dt, 0,
         0, 1,   0,
         0, 0,   1;
    _G << _dt*_dt*0.5*t_u_scale,
          _dt*t_u_scale,
          0;
    _Q = _G*_war_w*_G.transpose();
    _H_pos << 1, 0, 0;
    _R_pos = 0.05;
}

KalmanFilter::~KalmanFilter() {

}

void KalmanFilter::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0_ACC) {
        doPredictionStep(((FloatMsg*)t_msg)->data);
    }
    else if(t_port->getID() == ports_id::IP_1_POS) {
        doMeasurementStep(((FloatMsg*)t_msg)->data);
    }
    FloatMsg float_data;
    float_data.data = _x(0,1);
    this->_output_port_0->receiveMsgData((DataMsg*) &float_data);
}

void KalmanFilter::setTimeStep(float t_dt) {
    _dt = t_dt;
}

void KalmanFilter::doPredictionStep(float t_u) {
    _x = _F*_x + _G*t_u;
    _P = _F*_P*_F.transpose()+_Q;
}

void KalmanFilter::doMeasurementStep(float t_z) {
    float t_S = _H_pos*_P*_H_pos.transpose() + _R_pos;
    Eigen::Matrix<float, 3, 1> t_K = (_P*_H_pos.transpose())/t_S;
    _x = _x + t_K*(t_z - _H_pos*_x);
    _P = (Eigen::Matrix3f::Identity() - t_K*_H_pos)*_P;
}