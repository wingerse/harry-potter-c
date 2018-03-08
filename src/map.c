#include "map.h"
#include "assets.h"

#define MAP_SPEED 100

void Map_init(Map* map, int (*skeleton)[MAP_TILE_Y_COUNT][MAP_TILE_X_COUNT], Point pos)
{
    map->skeleton = skeleton;
    map->pos = pos;
}

bool Map_update(Map* map, float delta)
{
    map->pos.x -= MAP_SPEED * delta;
    return true;
}

bool Map_draw(Map* map, SDL_Renderer* renderer)
{
    for (int y = 0; y < MAP_TILE_Y_COUNT; y++) {
        for (int x = 0; x < MAP_TILE_X_COUNT; x++) {
            int tile = (*map->skeleton)[y][x];
            if (tile != 0) {
                ERR_IF(SDL_RenderCopy(renderer, asset_ground_unit_board,
                           &(SDL_Rect){ (tile - 1) * TILE_WIDTH, 0, TILE_WIDTH, TILE_HEIGHT },
                           &(SDL_Rect){ map->pos.x + x * TILE_WIDTH, map->pos.y + y * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT }),
                    == -1);
            }
        }
    }
    return true;
}