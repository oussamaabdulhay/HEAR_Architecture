#pragma once
#include "HEAR_math/Matrix3by3.hpp"
#include "HEAR_math/Vector3D.hpp"
#include <iostream>
#include <math.h>

class RotationMatrix3by3 : public Matrix3by3 {
    public:
        RotationMatrix3by3();
        ~RotationMatrix3by3();
        void Update(Vector3D<float>);
};
