#include "mainlevel.h"
#include "defs.h"
#include <SDL2/SDL.h>
#include "game.h"
#include "assets.h"
#include "maps.h"
#include <stdlib.h>
#include <stdio.h>

void MainLevel_reset(MainLevel* m, Game* game)
{
    m->game = game;
    Harry_init(&m->harry);
    Magic_init(&m->magic, m->harry.pos);

    Background_init(&m->sky, asset_sky_board, 0, 10, 3);
    Background_init(&m->castle, asset_castle_board, 190, 20, 3);
    Background_init(&m->magic1, asset_magic_board, 0, 130, 3);
    Background_init(&m->magic2, asset_magic_board, 0, 120, 3);

    Map_init(&m->map1, map_arrays[0], (Point){0, 0});
    Map_init(&m->map2, map_arrays[1], (Point){MAP_WIDTH, 0});
    m->magic_inited = false;
}

static void map_check_collision(Map* map, Harry* harry) 
{
    for (int y = 0; y < MAP_TILE_Y_COUNT; y++) {
        for (int x = 0; x < MAP_TILE_X_COUNT; x++) {
            int tile = (*map->skeleton)[y][x];
            int tile_x = (int)(map->pos.x + x * TILE_WIDTH);
            int tile_y = (int)(map->pos.y + y * TILE_HEIGHT);
            if (!harry->is_dead && tile != 0 && tile_x >= harry->pos.x - TILE_WIDTH && tile_x <= harry->pos.x + HARRY_FRAME_WIDTH + TILE_WIDTH && 
            tile_y >= harry->pos.y - TILE_HEIGHT && tile_y <= harry->pos.y + HARRY_FRAME_HEIGHT + TILE_HEIGHT) {
                Polygon p;
                Polygon_init(&p, tile_vertices[tile], tile_vertices_lens[tile], tile_axes[tile]);
                if (Polygon_intersects(&p, (SDL_Point){tile_x, tile_y}, &harry->current_polygon, (SDL_Point){(int)harry->pos.x, (int)harry->pos.y})) {
                    harry->is_dead = true;
                }
            }
        }
    }
}

static void MainLevel_check_collision(MainLevel *m) 
{
    map_check_collision(&m->map1, &m->harry);
    map_check_collision(&m->map2, &m->harry);
}

bool MainLevel_update(void* scene, float delta)
{
    MainLevel* this = scene;
    ERR_IF(Background_update(&this->sky, delta), == false);
    ERR_IF(Background_update(&this->castle, delta), == false);
    ERR_IF(Background_update(&this->magic1, delta), == false);
    ERR_IF(Background_update(&this->magic2, delta), == false);
    ERR_IF(Map_update(&this->map1, delta), == false);
    ERR_IF(Map_update(&this->map2, delta), == false);

    if (this->map1.pos.x <= -MAP_WIDTH) {
        Map_init(&this->map1, map_arrays[rand() % 15], (Point){this->map2.pos.x + MAP_WIDTH, 0});
    }
    if (this->map2.pos.x <= -MAP_WIDTH) {
        Map_init(&this->map2, map_arrays[rand() % 15], (Point){this->map1.pos.x + MAP_WIDTH, 0});
    }
    if (!this->harry.is_dead) {
        ERR_IF(Harry_update(&this->harry, delta), == false);
        MainLevel_check_collision(this);
    } 
    if (this->harry.is_dead) {
        if (!this->magic_inited) {
            Magic_init(&this->magic, this->harry.pos);
            this->magic_inited = true;
        }
        
        Magic_update(&this->magic, delta);
    }
    if (this->magic.anim.ended) {
        DeathMenu_reset(&death_menu, this->game, 10000);
        this->game->current_scene = (SceneInterface){&death_menu, &DeathMenu_SceneInterface_vtab};
    }

    return true;
}

bool MainLevel_draw(void* scene)
{
    MainLevel* this = scene;
    ERR_IF(Background_draw(&this->sky, this->game->renderer), == false);
    ERR_IF(Background_draw(&this->castle, this->game->renderer), == false);

    ERR_IF(Map_draw(&this->map1, this->game->renderer), == false);
    ERR_IF(Map_draw(&this->map2, this->game->renderer), == false);

    ERR_IF(Background_draw(&this->magic1, this->game->renderer), == false);
    ERR_IF(Background_draw(&this->magic2, this->game->renderer), == false);

    if (this->harry.is_dead) {
        ERR_IF(Magic_draw(&this->magic, this->game->renderer), == false);
    } else {
        ERR_IF(Harry_draw(&this->harry, this->game->renderer), == false);
    }

    return true;
}

SceneInterface_vtab MainLevel_SceneInterface_vtab = {MainLevel_update, MainLevel_draw};