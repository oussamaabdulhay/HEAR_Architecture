#pragma once

#include "common_srv/DataMsg.hpp"
#include "common_srv/Vector3D.hpp"
#include <vector>

class PointsMsg : public DataMsg
{

public:

    PointsMsg();
    ~PointsMsg();
    msg_type getType();
    const int getSize();

    std::vector<Vector3D<float>> points;
};