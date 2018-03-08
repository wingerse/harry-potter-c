#pragma once

#include "vec.h"
#include <stddef.h>

#define MAP_TILE_Y_COUNT 20
#define MAP_TILE_X_COUNT 30
#define TILE_WIDTH 16
#define TILE_HEIGHT 16

#define MAP_WIDTH (MAP_TILE_X_COUNT * TILE_WIDTH)

extern int (*map_arrays[15])[MAP_TILE_Y_COUNT][MAP_TILE_X_COUNT];

#define TILECOUNT 114

extern Vec* tile_vertices[TILECOUNT];
extern size_t tile_vertices_lens[TILECOUNT];
// lens same as vertices_lens
extern Vec* tile_axes[TILECOUNT];

void init_tile_axes();