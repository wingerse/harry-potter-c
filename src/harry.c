#include "harry.h"
#include "assets.h"
#include "defs.h"
#include "vec.h"
#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>

#define HARRY_SPEED 150
#define HARRY_ANIM_FRAMES 13
#define HARRY_ANIM_DELAY 0.2f


static Vec harry0_vertices[] = { { 0/2, 59/2 }, { 58/2, 1/2 }, { 93/2, 45/2 } };
static Vec harry1_vertices[] = { { 0/2, 50/2 }, { 67/2, 4/2 }, { 93/2, 53/2 } };
static Vec harry2_vertices[] = { { 0/2, 50/2 }, { 67/2, 4/2 }, { 93/2, 53/2 } };
static Vec harry3_vertices[] = { { 0/2, 55/2 }, { 14/2, 6/2 }, { 67/2, 4/2 }, { 93/2, 53/2 } };
static Vec harry4_vertices[] = { { 0/2, 55/2 }, { 14/2, 6/2 }, { 67/2, 4/2 }, { 93/2, 53/2 } };
static Vec harry5_vertices[] = { { 0/2, 55/2 }, { 14/2, 6/2 }, { 67/2, 4/2 }, { 93/2, 53/2 } };
static Vec harry6_vertices[] = { { 0/2, 59/2 }, { 58/2, 1/2 }, { 93/2, 45/2 } };
static Vec harry7_vertices[] = { { 0/2, 59/2 }, { 58/2, 1/2 }, { 93/2, 45/2 } };
static Vec harry8_vertices[] = { { 0/2, 64/2 }, { 45/2, 0/2 }, { 96/2, 40/2 } };
static Vec harry9_vertices[] = { { 0/2, 64/2 }, { 48/2, 0/2 }, { 96/2, 36/2 } };
static Vec harry10_vertices[] = { { 4/2, 64/2 }, { 8/2, 28/2 }, { 52/2, 0/2 }, { 96/2, 36/2 } };
static Vec harry11_vertices[] = { { 4/2, 64/2 }, { 8/2, 28/2 }, { 52/2, 0/2 }, { 96/2, 36/2 } };
static Vec harry12_vertices[] = { { 0/2, 64/2 }, { 48/2, 0/2 }, { 95/2, 35/2 } };

static Vec* harry_vertices[HARRY_ANIM_FRAMES] = {
    harry0_vertices, harry1_vertices, harry2_vertices, harry3_vertices,
    harry4_vertices, harry5_vertices, harry6_vertices, harry7_vertices,
    harry8_vertices, harry9_vertices, harry10_vertices, harry11_vertices,
    harry12_vertices
};

static size_t harry_vertices_lens[HARRY_ANIM_FRAMES] = {
    ARRAYSIZE(harry0_vertices), ARRAYSIZE(harry1_vertices), ARRAYSIZE(harry2_vertices), ARRAYSIZE(harry3_vertices),
    ARRAYSIZE(harry4_vertices), ARRAYSIZE(harry5_vertices), ARRAYSIZE(harry6_vertices), ARRAYSIZE(harry7_vertices),
    ARRAYSIZE(harry8_vertices), ARRAYSIZE(harry9_vertices), ARRAYSIZE(harry10_vertices), ARRAYSIZE(harry11_vertices),
    ARRAYSIZE(harry12_vertices)
};

static Vec harry0_axes[ARRAYSIZE(harry0_vertices)];
static Vec harry1_axes[ARRAYSIZE(harry1_vertices)];
static Vec harry2_axes[ARRAYSIZE(harry2_vertices)];
static Vec harry3_axes[ARRAYSIZE(harry3_vertices)];
static Vec harry4_axes[ARRAYSIZE(harry4_vertices)];
static Vec harry5_axes[ARRAYSIZE(harry5_vertices)];
static Vec harry6_axes[ARRAYSIZE(harry6_vertices)];
static Vec harry7_axes[ARRAYSIZE(harry7_vertices)];
static Vec harry8_axes[ARRAYSIZE(harry8_vertices)];
static Vec harry9_axes[ARRAYSIZE(harry9_vertices)];
static Vec harry10_axes[ARRAYSIZE(harry10_vertices)];
static Vec harry11_axes[ARRAYSIZE(harry11_vertices)];
static Vec harry12_axes[ARRAYSIZE(harry12_vertices)];

static Vec* harry_axes[HARRY_ANIM_FRAMES] = {
    harry0_axes, harry1_axes, harry2_axes, harry3_axes,
    harry4_axes, harry5_axes, harry6_axes, harry7_axes,
    harry8_axes, harry9_axes, harry10_axes, harry11_axes,
    harry12_axes
};

void init_harry_axes()
{
    for (size_t i = 0; i < HARRY_ANIM_FRAMES; i++) {
        Vec* vertices = harry_vertices[i];
        Vec* axes = harry_axes[i];
        for (size_t j = 0; j < harry_vertices_lens[i]; j++) {
            Vec edge = Vec_sub(vertices[j], vertices[j + 1 == harry_vertices_lens[i] ? 0 : j + 1]);
            Vec normal = { -edge.y, edge.x };
            axes[j] = normal;
        }
    }
}

void Harry_init(Harry* harry)
{
    harry->state = HarryState_DOWN;
    harry->pos = (Point){ 100, 100 };
    Animation_init(&harry->anim_init_up, 7, 9, HARRY_ANIM_DELAY, false);
    Animation_init(&harry->anim_up, 10, 12, HARRY_ANIM_DELAY, true);
    Animation_init(&harry->anim_init_down, 0, 2, HARRY_ANIM_DELAY, false);
    Animation_init(&harry->anim_down, 3, 5, HARRY_ANIM_DELAY, true);
    harry->current_animation = &harry->anim_down;
    harry->is_dead = false;
}

void Harry_change_anim(Harry* harry, Animation* anim)
{
    Animation_reset(harry->current_animation);
    harry->current_animation = anim;
}

bool Harry_update(Harry* harry, float delta)
{
    const Uint8* keyboardstate = SDL_GetKeyboardState(NULL);

    Animation_update(harry->current_animation, delta);

    int current_frame = harry->current_animation->current_frame;
    Polygon_init(&harry->current_polygon, harry_vertices[current_frame], harry_vertices_lens[current_frame], harry_axes[current_frame]);

    if (keyboardstate[SDL_SCANCODE_UP]) {
        harry->pos.y -= HARRY_SPEED * delta;
        if (harry->pos.y < 0)
            harry->pos.y = 0;
        if (harry->state == HarryState_DOWN) {
            Harry_change_anim(harry, &harry->anim_init_up);
        }
        if (harry->current_animation->ended) {
            Harry_change_anim(harry, &harry->anim_up);
        }
        harry->state = HarryState_UP;
    } else {
        harry->pos.y += HARRY_SPEED * delta;
        if (harry->pos.y + HARRY_FRAME_HEIGHT > LOGICAL_HEIGHT) {
            harry->pos.y = LOGICAL_HEIGHT - HARRY_FRAME_HEIGHT;
        }
        if (harry->state == HarryState_UP) {
            Harry_change_anim(harry, &harry->anim_init_down);
        }
        if (harry->current_animation->ended) {
            Harry_change_anim(harry, &harry->anim_down);
        }
        harry->state = HarryState_DOWN;
    }

    return true;
}

bool Harry_draw(Harry* harry, SDL_Renderer* renderer)
{
    ERR_IF(SDL_RenderCopy(renderer, asset_harry,
               &(SDL_Rect){ harry->current_animation->current_frame * HARRY_FRAME_WIDTH, 0, HARRY_FRAME_WIDTH, HARRY_FRAME_HEIGHT },
               &(SDL_Rect){ (int)harry->pos.x, (int)round(harry->pos.y), HARRY_FRAME_WIDTH, HARRY_FRAME_HEIGHT }),
        == -1);
    return true;
}

void Magic_init(Magic* magic, Point pos)
{
    magic->pos = pos;
    Animation_init(&magic->anim, 0, 9, 0.2f, false);
}

bool Magic_update(Magic* magic, float delta)
{
    Animation_update(&magic->anim, delta);
    return true;
}

#define MAGIC_FRAME_WIDTH 40
#define MAGIC_FRAME_HEIGHT 40

bool Magic_draw(Magic* magic, SDL_Renderer* renderer)
{
    ERR_IF(SDL_RenderCopy(renderer, asset_explosion, 
    &(SDL_Rect){magic->anim.current_frame * MAGIC_FRAME_WIDTH, 0, MAGIC_FRAME_WIDTH, MAGIC_FRAME_HEIGHT}, 
            &(SDL_Rect){(int)magic->pos.x, (int)magic->pos.y, MAGIC_FRAME_WIDTH, MAGIC_FRAME_HEIGHT}), == -1);
    return true;
}
