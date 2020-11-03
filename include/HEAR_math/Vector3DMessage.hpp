#pragma once
#include "common_srv/DataMsg.hpp"
#include "common_srv/Vector3D.hpp"

class Vector3DMessage : public DataMsg{

private:
    msg_type _type;
    Vector3D<float> _data;

public:

    msg_type getType();
    const int getSize();
    Vector3D<float> getData();
    
    Vector3DMessage();
    ~Vector3DMessage();

    void setVector3DMessage(Vector3D<float>);
};