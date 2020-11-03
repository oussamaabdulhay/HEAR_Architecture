#pragma once
#include "common_srv/DataMsg.hpp"
#include "common_srv/Vector3D.hpp"

class Vector3DMsg : public DataMsg{

private:
    msg_type _type;
    Vector3D<float> _data;

public:

    msg_type getType();
    const int getSize();
    Vector3D<float> getData();
    
    Vector3DMsg();
    ~Vector3DMsg();

    void setVector3DMsg(Vector3D<float>);
};
