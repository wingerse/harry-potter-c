#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "animation.h"
#include "collision.h"
#include "defs.h"
#include <stdbool.h>

#define HARRY_FRAME_WIDTH 48
#define HARRY_FRAME_HEIGHT 32

typedef enum HarryState {
    HarryState_UP,
    HarryState_DOWN
} HarryState;

typedef struct Harry {
    Point pos;
    HarryState state;
    Animation anim_init_up;
    Animation anim_up;
    Animation anim_init_down;
    Animation anim_down;
    Animation* current_animation;

    Polygon current_polygon;
    bool is_dead;
} Harry;

void init_harry_axes();
void Harry_init(Harry* harry);
bool Harry_update(Harry* harry, float delta);
bool Harry_draw(Harry* harry, SDL_Renderer* renderer);

typedef struct Magic {
    Point pos;
    Animation anim;
} Magic;

void Magic_init(Magic* magic, Point pos);
bool Magic_update(Magic* magic, float delta);
bool Magic_draw(Magic* magic, SDL_Renderer* renderer);