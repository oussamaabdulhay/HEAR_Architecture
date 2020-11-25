#include "HEAR_math/RotationMatrix3by3.hpp"


RotationMatrix3by3::RotationMatrix3by3(/* args */){
}

RotationMatrix3by3::~RotationMatrix3by3(){
}

Eigen::Matrix<float, 3, 3> RotationMatrix3by3::Update(Vector3D<float> t_input)
{ 
    
    Matrix3by3::v1.x =  cos(t_input.x)*cos(t_input.z) - sin(t_input.x)*sin(t_input.y)*sin(t_input.z);
    Matrix3by3::v1.y =  sin(t_input.z)*cos(t_input.y);
    Matrix3by3::v1.z = -sin(t_input.x)*cos(t_input.z)-cos(t_input.x)*sin(t_input.y)*sin(t_input.z);

    Matrix3by3::v2.x = -cos(t_input.x)*sin(t_input.z) - sin(t_input.x)*sin(t_input.y)*cos(t_input.z);
    Matrix3by3::v2.y =  cos(t_input.z)*cos(t_input.y);
    Matrix3by3::v2.z =  sin(t_input.x)*sin(t_input.z)-cos(t_input.x)*sin(t_input.y)*cos(t_input.z);

    Matrix3by3::v3.x =  sin(t_input.x)*cos(t_input.y);
    Matrix3by3::v3.y =  sin(t_input.y);
    Matrix3by3::v3.z =  cos(t_input.x)*cos(t_input.y);

   _m << v1.x, v2.x, v3.x,
         v1.y, v2.y, v3.y,
         v1.z, v2.z, v3.z;

    return _m;
}