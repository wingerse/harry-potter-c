#pragma once

#include "defs.h"
#include <SDL.h>
#include <stdbool.h>
#include "maps.h"

typedef struct Map {
    int (*skeleton)[MAP_TILE_Y_COUNT][MAP_TILE_X_COUNT];
    Point pos;
} Map;

void Map_init(Map* map, int (*skeleton)[MAP_TILE_Y_COUNT][MAP_TILE_X_COUNT], Point pos);
bool Map_update(Map* map, float delta);
bool Map_draw(Map* map, SDL_Renderer* renderer);

