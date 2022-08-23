//
// Created by Caaaarl on 2022-08-22.
//

#include "timer.h"

void timer::start() {
    startpt = std::chrono::steady_clock::now();
}

void timer::stop() {
    endpt = std::chrono::steady_clock::now();
}

double timer::elapsedSec() {
    std::chrono::duration<double> elapsed_seconds = endpt-startpt;
    return elapsed_seconds.count();
}
