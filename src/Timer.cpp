#include "HEAR_core/Timer.hpp"

void Timer::tick() {
    _start=std::chrono::system_clock::now();
}
int Timer::tockMicroSeconds() {
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - _start).count();
}
int Timer::tockMilliSeconds() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - _start).count();
}