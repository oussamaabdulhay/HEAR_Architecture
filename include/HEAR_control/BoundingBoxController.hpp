#pragma once
#include <math.h>
#include "HEAR_core/Timer.hpp"
#include "HEAR_core/logger.hpp"
#include "HEAR_msg/FloatMsg.hpp"
#include "HEAR_msg/IntegerMsg.hpp"
#include "HEAR_msg/Vector3DMsg.hpp"
#include "HEAR_msg/ControllerMsg.hpp"
#include "HEAR_control/Controller.hpp"
#include "HEAR_control/BB_values.hpp"

class BoundingBoxController : public Controller {
private:
    Port* _input_port_0;
    Port* _input_port_1;
    Port* _input_port_2;
    Port* _output_port;
	Timer _timer;
	block_id _id;
	float _dt;
	FloatMsg _command_msg;
    double _alpha1, _alpha2, _h1, _h2;
	double _command = 0;
public:
    enum ports_id {IP_0_DATA, IP_1_UPDATE, IP_2_RESET, OP_0_DATA};
	void process(DataMsg* t_msg, Port* t_port);
    void reset();
    void initialize(BB_parameters*);
	void runTask(DataMsg*);
    block_id getID(){ return _id; }
    float bounding_box_algorithm(float);

    BoundingBoxController(block_id t_id);
    ~BoundingBoxController();
};
