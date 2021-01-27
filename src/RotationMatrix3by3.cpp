#include "HEAR_math/RotationMatrix3by3.hpp"


RotationMatrix3by3::RotationMatrix3by3(/* args */) : _m(3,3){
    
}

RotationMatrix3by3::~RotationMatrix3by3(){
}

Eigen::MatrixXd RotationMatrix3by3::Update(Vector3D<float> t_input)
{ 

    float sr = sin(t_input.x);
    float cr = cos(t_input.x);

    float sp = sin(t_input.y);
    float cp = cos(t_input.y);

    float sy = sin(t_input.z);
    float cy = cos(t_input.z);
    
//     Matrix3by3::v1.x = cp * cy;
//     Matrix3by3::v1.y = sr * sp * cy - cr * sy;
//     Matrix3by3::v1.z = cr * sp * cy + sr * sy;

//     Matrix3by3::v2.x = cp * sy;
//     Matrix3by3::v2.y = sr * sp * sy + cr * cy;
//     Matrix3by3::v2.z = cr * sp * sy - sr * cy;

//     Matrix3by3::v3.x = sp * -1;
//     Matrix3by3::v3.y = cp * sr;
//     Matrix3by3::v3.z = cp * cr;

//     Matrix3by3::v1.x = cp * cy;
//     Matrix3by3::v1.y = sr * sp * cy - cr * sy;
//     Matrix3by3::v1.z = cr * sp * cy + sr * sy;

//     Matrix3by3::v2.x = cp * sy;
//     Matrix3by3::v2.y = sr * sp * sy + cr * cy;
//     Matrix3by3::v2.z = cr * sp * sy - sr * cy;

//     Matrix3by3::v3.x = sp * -1;
//     Matrix3by3::v3.y = cp * sr;
//     Matrix3by3::v3.z = cp * cr;

    _m(0,0) = cy * cp;
    _m(1,0) = sy * cp;
    _m(2,0) = -1 * sp;

    _m(0,1) = (sy * cr * -1)+(cy * sp * sr);
    _m(1,1) = cy * cr + sp * sy * sr;
    _m(1,2) = cp * sr;

    _m(0,2) = sy * sr + cy * sp *cr;
    _m(1,2) = (-1 * cy * sr) + (sp * sy *cr);
    _m(2,2) = cp * cr;

    // _m << v1.x, v2.x, v3.x,
    //      v1.y, v2.y, v3.y,
    //      v1.z, v2.z, v3.z;

    return _m;
}