#pragma once
#include "HEAR_core/DataMsg.hpp"
#include "HEAR_math/Vector3D.hpp"

class filterPointMsg : public DataMsg {

public:
    Vector3D<float> filterPoint;
    msg_type getType();
    const int getSize();
    filterPointMsg();
    ~filterPointMsg();
};