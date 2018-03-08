#pragma once

#include <stdbool.h>
#include "vec.h"
#include <stddef.h>
#include <SDL.h>

typedef struct Projection {
    int min, max;
} Projection;

bool Projection_overlaps(Projection a, Projection b);

typedef struct Polygon {
    Vec* vertices;
    size_t vertices_len;
    Vec* axes;
} Polygon;

void Polygon_init(Polygon* p, Vec* vertices, size_t vertices_len, Vec* axes);
bool Polygon_intersects(Polygon* a, SDL_Point a_pos, Polygon* b, SDL_Point b_pos);
