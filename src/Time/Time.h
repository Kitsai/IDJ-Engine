//
// Created by luck3 on 5/19/2024.
//

#ifndef IDJ_ENGINE_TIME_H
#define IDJ_ENGINE_TIME_H

#include "SDL2/SDL.h"

class Time {
private:
    static unsigned last_frame;
    static unsigned current_frame;
    static double time_accumulator;


public:
    static double delta_time;
    static double time_elapsed;

    static void update();
};

#endif //IDJ_ENGINE_TIME_H
