#pragma once
#include "pthread.h"
#include <unistd.h>
#include "HEAR_misc/logger.hpp"
#include "HEAR_mission/MissionPipeline.hpp"

class MissionScenario {
    static pthread_mutex_t execution_control;
    static pthread_cond_t  condition_cond;
    static bool _start_locked;
    public:
    void AddMissionPipeline(MissionPipeline*);
    void StartScenario();
    void ResetScenario();
    static void* pipelineThreadStarter(void* arg);
    MissionScenario();
};