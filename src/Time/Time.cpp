//
// Created by luck3 on 5/19/2024.
//

#include "Time.h"

unsigned Time::last_frame = 0;
unsigned Time::current_frame = SDL_GetPerformanceCounter();
double Time::time_accumulator = 0;


double Time::delta_time = 0;
double Time::time_elapsed = 0;


void Time::update() {
    last_frame = current_frame;
    current_frame = SDL_GetPerformanceCounter();

    const unsigned freq = SDL_GetPerformanceFrequency();

    time_elapsed = (double)(current_frame/(double)freq);
    delta_time = (double)((current_frame-last_frame)/(double)freq);
    time_elapsed += delta_time;
}