#include "animation.h"

void Animation_reset(Animation* animation) 
{
    animation->timer = 0; 
    animation->current_frame = animation->start_frame;
    animation->ended = false;
}

void Animation_init(Animation* animation, int start_frame, int end_frame, float delay, bool loop) 
{
    animation->start_frame = start_frame;
    animation->end_frame = end_frame;
    animation->delay = delay;
    animation->loop = loop;

    Animation_reset(animation);
}

void Animation_update(Animation* animation, float delta)
{
    animation->timer += delta;
    if (animation->timer >= animation->delay) {
        if (!animation->ended) {
            animation->current_frame++;

            if (animation->current_frame > animation->end_frame) {
                if (animation->loop)
                    animation->current_frame = animation->start_frame;
                else 
                    animation->ended = true;
            }
        }

        animation->timer = 0;
    }
}
