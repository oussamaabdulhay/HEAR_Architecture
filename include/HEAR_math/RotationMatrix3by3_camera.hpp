#pragma once
#include "Eigen/Core"
#include "HEAR_math/Matrix3by3.hpp"
#include <math.h>

class RotationMatrix3by3_camera : public Matrix3by3 {
    private:
       Eigen::MatrixXd _m;
    public:
        RotationMatrix3by3_camera();
        ~RotationMatrix3by3_camera();
        Eigen::MatrixXd Update(Vector3D<float>);
};