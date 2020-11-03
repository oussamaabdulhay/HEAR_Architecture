#pragma once
#include "HEAR_misc/common_types.hpp"
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"
#include "HEAR_core/Block.hpp"
#include "HEAR_msg/FloatMsg.hpp"

class ButterFilter_2nd: public Block {
private:
    Port* _input_port_0;
    Port* _output_port;
    float _ip_0 = 0;
    float prev_y=0, prev2_y=0, prev_x=0, prev2_x=0;
    const float coeff_120Hz_2nd_butter_5hz[5] = { -1.279632424997809,0.477592250072517,0.049489956268677,0.098979912537354,0.049489956268677 };
    const float coeff_200Hz_2nd_butter[5] = { -1.97779f, 0.97803f, 6.1006e-05f, 1.2201e-04f, 6.1006e-05f };
    const float coeff_200Hz_2nd_butter_50hz[5] = {-1.561018075800718, 0.641351538057563, 0.020083365564211, 0.040166731128423, 0.020083365564211};
    const float* _coeff_in_use;
public:
    enum ports_id {IP_0_DATA,OP_0_DATA};
    enum BF_settings {FS120FC5, FS200FC10, FS200FC50};
    void runTask(DataMsg*);
    void process(DataMsg* t_msg, Port* t_port);
    ButterFilter_2nd(BF_settings t_settings);
    ~ButterFilter_2nd();
};