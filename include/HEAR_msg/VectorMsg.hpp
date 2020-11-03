#pragma once
#include "common_srv/DataMsg.hpp"
#include "common_srv/Vector3D.hpp"

class VectorMsg : public DataMsg{

public:

    VectorMsg();
    ~VectorMsg();
    msg_type getType();
    const int getSize();

    Vector3D<float> p1, p2;
};