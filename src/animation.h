#pragma once

#include <stdbool.h>
#include <SDL2/SDL.h>

typedef struct Animation {
    int current_frame;
    int start_frame;
    int end_frame;
    float delay;
    float timer;

    bool loop;
    bool ended;
} Animation;

void Animation_init(Animation* animation, int start_frame, int end_frame, float delay, bool loop);
void Animation_update(Animation* animation, float delta);
void Animation_reset(Animation* animation);