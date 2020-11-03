#pragma once
#include "HEAR_core/DataMsg.hpp"
#include "HEAR_math/Vector3D.hpp"

class filterPointMsg : public DataMsg {
public:
    Vector3D<float> filterPoint;
    msg_type getType() {return msg_type::FILTER_POINT;};
    const int getSize() {return sizeof(filterPointMsg);};
    filterPointMsg() {};
    ~filterPointMsg() {};
};