#pragma once
#include "HEAR_core/DataMsg.hpp"
#include "HEAR_math/Vector3D.hpp"

class Vector3DMsg : public DataMsg {
public:
    msg_type getType() {return msg_type::VECTOR3D;};
    const int getSize() {return sizeof(*this);};
    Vector3DMsg() {};
    ~Vector3DMsg() {};
    Vector3D<float> data;
};
