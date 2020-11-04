#pragma once

#include "HEAR_core/DataMsg.hpp"
#include "HEAR_math/Vector3D.hpp"
#include <vector>

class PointsMsg : public DataMsg
{
public:
    PointsMsg() {};
    ~PointsMsg() {};
    msg_type getType() {return msg_type::POINTS;};
    const int getSize() {return sizeof(*this);};
    std::vector<Vector3D<float>> points;
};