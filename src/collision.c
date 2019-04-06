#include "collision.h"
#include "vec.h"
#include <stddef.h>
#include <SDL2/SDL.h>

bool Projection_overlaps(Projection a, Projection b)
{
    return !(a.min < b.min && a.max < b.min) && !(b.min < a.min && b.max < a.min);
}

void Polygon_init(Polygon* p, Vec* vertices, size_t vertices_len, Vec* axes)
{
    p->vertices = vertices;
    p->vertices_len = vertices_len;
    p->axes = axes;
}

static Projection Polygon_project(Polygon* p, Vec axis, SDL_Point pos) 
{
    int min = Vec_dot(axis, Vec_add((Vec){pos.x, pos.y}, p->vertices[0]));
    int max = min;
    for (size_t i = 0; i < p->vertices_len; i++) {
        int val = Vec_dot(axis, Vec_add((Vec){pos.x, pos.y}, p->vertices[i]));
        if (val < min) min = val;
        else if (val > max) max = val;
    }

    return (Projection){min, max};
}

bool Polygon_intersects(Polygon* a, SDL_Point a_pos, Polygon* b, SDL_Point b_pos)
{
    for (size_t i = 0; i < a->vertices_len; i++) {
        Vec axis = a->axes[i];
        Projection a_proj = Polygon_project(a, axis, a_pos);
        Projection b_proj = Polygon_project(b, axis, b_pos);

        if (!Projection_overlaps(a_proj, b_proj))
            return false;
    }

    for (size_t i = 0; i < a->vertices_len; i++) {
        Vec axis = b->axes[i];
        Projection a_proj = Polygon_project(a, axis, a_pos);
        Projection b_proj = Polygon_project(b, axis, b_pos);

        if (!Projection_overlaps(a_proj, b_proj))
            return false;
    }

    return true;
}
