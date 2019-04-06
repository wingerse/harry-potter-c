#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct Background {
    SDL_Texture* texture;
    int w, h;
    float x;
    int y;
    int speed;
    int images_needed;
} Background;

void Background_init(Background* bg, SDL_Texture* texture, int y, int speed, int images_needed);
bool Background_update(Background* bg, float delta);
bool Background_draw(Background* bg, SDL_Renderer* renderer);