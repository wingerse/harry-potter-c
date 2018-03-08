#pragma once

#include <SDL.h>
#include <stdbool.h>
#include "startmenu.h"
#include "deathmenu.h"
#include "mainlevel.h"
#include "scene.h"

extern StartMenu start_menu;
extern DeathMenu death_menu;
extern MainLevel main_level;

typedef struct Game {
    SDL_Window *window;
    SDL_Renderer *renderer;

    SceneInterface current_scene;

    Uint64 perf_freq;
    bool quit;
    Uint64 prev_tick;
} Game;

bool Game_run(Game *game);
void Game_exit(Game *game);
void Game_destroy(Game *game);
