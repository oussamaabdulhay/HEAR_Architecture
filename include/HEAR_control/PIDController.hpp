#pragma once
#include "HEAR_core/Block.hpp"
#include <math.h>
#include "HEAR_msg/ControllerMsg.hpp"
#include "PID_values.hpp"
#include "HEAR_msg/FloatMsg.hpp"
#include "Controller.hpp"
#include "HEAR_msg/Vector3DMsg.hpp"
#include "HEAR_msg/FloatMsg.hpp"
#include "HEAR_core/logger.hpp"
#include "HEAR_msg/IntegerMsg.hpp"
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"

class PIDController : public Controller{

    private:
        block_id _id;
        FloatMsg _command_msg;
        Port* _input_port_0;
        Port* _input_port_1;
        Port* _input_port_2;
        Port* _output_port;
        //Chehadeh's code
        PID_parameters _parameters;
        bool i_term, d_term, dd_term; //Comparing against booleans is faster
        float _dt;
	    bool en_pv_derivation = true, en_anti_windup = false;
        void set_internal_sw(PID_parameters pid_para_x);
        //---------------
        
    public:
        enum ports_id {IP_0_DATA, IP_1_UPDATE, IP_2_RESET, OP_0_DATA};
        void process(DataMsg* t_msg, Port* t_port);
        //Chehadeh's code
        float prev_err = 0, prev2_err = 0, prev_pv_rate = 0, accum_u = 0, accum_I = 0;
        void initialize(PID_parameters);
        float pid_inc(float err, float pv_first, float pv_second=-1);
        float pid_direct(float err, float pv_first, float pv_second=-1);
        void set_I_term(float);
        //---------------
        void update_params(PID_parameters*);
        void reset();
        void runTask(DataMsg*);
        block_id getID(){ return _id; }
       
        PIDController(block_id t_id);
        ~PIDController();
};
