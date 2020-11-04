#pragma once
#include "HEAR_core/DataMsg.hpp"
#include "HEAR_math/Vector3D.hpp"
#include "HEAR_math/Quaternion.hpp"

class IMUMsg : public DataMsg {
public:
    Vector3D<float> _angular_velocity, _orientation_euler;
    Quaternion _orientation; 
    msg_type getType() {return msg_type::IMU;};
    const int getSize() {return sizeof(*this);};
    IMUMsg() {};
    ~IMUMsg() {};
};