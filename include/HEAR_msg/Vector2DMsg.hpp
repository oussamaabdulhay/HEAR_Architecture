#pragma once
#include "HEAR_core/DataMsg.hpp"
#include "HEAR_math/Vector2D.hpp"

class Vector2DMsg : public DataMsg {
public:
    Vector2DMsg();
    ~Vector2DMsg();
    msg_type getType() {return msg_type::VECTOR2D;};
    const int getSize() {return sizeof(*this);};
    Vector2D<float> data;
};