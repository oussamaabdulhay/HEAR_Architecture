#pragma once
#include "Eigen/Core"
#include "HEAR_math/Matrix3by3.hpp"
#include <math.h>

class RotationMatrix3by3 : public Matrix3by3 {
    private:
       Eigen::MatrixXd _m;
    public:
        RotationMatrix3by3();
        ~RotationMatrix3by3();
        Eigen::MatrixXd Update(Vector3D<float>);
};