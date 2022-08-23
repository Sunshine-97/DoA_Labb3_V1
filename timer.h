//
// Created by Caaaarl on 2022-08-22.
//

#ifndef DOA_LABB3_V1_TIMER_H
#define DOA_LABB3_V1_TIMER_H

#include <chrono>

class timer {
    std::chrono::time_point<std::chrono::steady_clock> startpt, endpt;
public:
    void start();
    void stop();
    double elapsedSec();
};


#endif //DOA_LABB3_V1_TIMER_H
