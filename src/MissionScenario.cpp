#include "HEAR_mission/MissionScenario.hpp"

pthread_mutex_t MissionScenario::execution_control=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  MissionScenario::condition_cond  = PTHREAD_COND_INITIALIZER;
bool MissionScenario::_start_locked=true;

MissionScenario::MissionScenario(){

}
void MissionScenario::AddMissionPipeline(MissionPipeline* t_flight_pipeline){
    pthread_t ptid; 
    // Creating a new thread 
    pthread_create(&ptid, NULL, &pipelineThreadStarter, (void*)t_flight_pipeline); 
}

void MissionScenario::StartScenario(){
    usleep(100000);
    MissionScenario::_start_locked=false;
}

void MissionScenario::ResetScenario(){

}
//void* MissionScenario::pipelineThreadStarter(void* arg);

void* MissionScenario::pipelineThreadStarter(void* arg){
    Logger::getAssignedLogger()->log("pthread_cond_wait",LoggerLevel::Info);
    //pthread_cond_wait( &condition_cond, &execution_control );
    while (MissionScenario::_start_locked)
    {
        /* code */
    }
    Logger::getAssignedLogger()->log("((MissionPipeline*)arg)->execute()",LoggerLevel::Info);
    ((MissionPipeline*)arg)->execute();
    return 0;
}