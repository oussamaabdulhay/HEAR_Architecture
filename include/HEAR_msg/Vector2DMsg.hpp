#pragma once
#include "HEAR_core/DataMsg.hpp"
#include "HEAR_math/Vector2D.hpp"

class Vector2DMsg : public DataMsg {
public:
    Vector2DMsg();
    ~Vector2DMsg();
    msg_type getType();
    const int getSize();
    Vector2D<float> data;
};