#pragma once
#include "HEAR_core/DataMsg.hpp"
#include "HEAR_math/Vector3D.hpp"

class Vector3DMsg : public DataMsg {
public:
    msg_type getType();
    const int getSize();
    Vector3D<float> getData();
    Vector3DMsg();
    ~Vector3DMsg();
    Vector3D<float> data;
};
