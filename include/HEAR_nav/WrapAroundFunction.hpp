#pragma once
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"
#include "HEAR_core/Block.hpp"
#include "HEAR_msg/FloatMsg.hpp"

class WrapAroundFunction : public Block {
private:
    double _min_val,_max_val,_span;
    double _input;
    double _output;
    Port* _input_port;
    Port* _output_port;
public:
    double wrapAround(double input);
    enum ports_id {IP_0_DATA, OP_0_DATA};
    WrapAroundFunction(double t_min_val,double t_max_val);
    void process(DataMsg* t_msg, Port* t_port);
    DataMsg* runTask(DataMsg*);
};