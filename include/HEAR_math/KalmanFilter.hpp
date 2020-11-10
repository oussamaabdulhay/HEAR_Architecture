#pragma once

// #include "Eigen/Core.h"
// #include "HEAR_core/InputPort.hpp"
// #include "HEAR_core/OutputPort.hpp"
// #include "HEAR_core/Block.hpp"
// #include "HEAR_msg/FloatMsg.hpp"

// class KalmanFilter : public Block {
//     private:
//         Port* _input_port_0;
//         Port* _input_port_1;
//         Port* _output_port_0;

//         Eigen::Matrix<float, 3, 1> x_prev, x;
//         Eigen::Matrix<float, 3, 3> P;
//         Eigen::Matrix<float, 3, 3> F;

//     public:
//         enum ports_id {IP_0_ACC, IP_1_POS, OP_0_VEL};
//         void process(DataMsg* t_msg, Port* t_port);
//         KalmanFilter();
//         ~KalmanFilter();
// };