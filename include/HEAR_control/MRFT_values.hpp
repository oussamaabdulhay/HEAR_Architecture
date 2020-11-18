#pragma once
#include <stdint.h>
#include "HEAR_core/common_types.hpp"

class MRFT_bag {
public:
	float amplitude;
    uint32_t duration;   
};

class MRFT_parameters {
public:
	float beta=0;
	float relay_amp=0;
	float bias=0;
	int no_switch_delay_in_ms=20;
	int num_of_peak_conf_samples=5;
	block_id id = block_id::NULL_ID;	   
};

class MRFT_data {
public:
	float err;
	bool mrft_bag_ready_para;
	MRFT_bag mrft_period;
};
