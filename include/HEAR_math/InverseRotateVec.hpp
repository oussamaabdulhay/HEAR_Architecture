#pragma once
#include "Eigen/Eigen"
#include "HEAR_math/RotationMatrix3by3.hpp"
#include "HEAR_msg/Vector3DMsg.hpp"
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"
#include "HEAR_core/Block.hpp"

class InverseRotateVec : public Block {
    private:
        Port* _input_port_0;
        Port* _input_port_1;
        Port* _input_port_2;
        Port* _input_port_3;
        Port* _output_port;
        Vector3D<float> _vec_data, _body_orientation, _rotated_unit_vector;
        Vector3D<float> _rotated_vec;
        RotationMatrix3by3 _body_rotation_matrix;
    public:
        void process(DataMsg* t_msg, Port* t_port);
        void rotateVector(Eigen::Matrix<float, 3, 3>);
        void updateRotationMatrix();
        enum ports_id {IP_0_VEC,IP_1_ROLL,IP_2_PITCH,IP_3_YAW,OP_0_DATA};
        InverseRotateVec();
        ~InverseRotateVec();
};