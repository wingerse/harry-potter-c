#include "game.h"
#include "assets.h"
#include "defs.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>
#include "startmenu.h"
#include "deathmenu.h"
#include "maps.h"
#include "harry.h"
#include <stdio.h>

StartMenu start_menu;
DeathMenu death_menu;
MainLevel main_level;

static bool Game_init(Game* game)
{
    int res;
    res = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    if (res != 0)
        return false;

    res = IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    if (!(res & IMG_INIT_PNG) || !(res & IMG_INIT_JPG))
        return false;

    res = Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    if (res < 0)
        return false;

    game->window = SDL_CreateWindow("Harry Potter",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN);
    if (game->window == NULL) 
        return false;
    
    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    if (game->renderer == NULL)
        return false;
    
    if (!load_assets(game->renderer))
        return false;
    
    StartMenu_reset(&start_menu, game);
    game->current_scene = (SceneInterface){&start_menu, &StartMenu_SceneInterface_vtab};

    Mix_PlayMusic(asset_music, -1);
    game->quit = false;
    
    game->perf_freq = SDL_GetPerformanceFrequency();
    SDL_RenderSetLogicalSize(game->renderer, LOGICAL_WIDTH, LOGICAL_HEIGHT);
    init_tile_axes();
    init_harry_axes();
    return true;
}

static void handle_events(Game *game) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            game->quit = true;
            break;
        }
    }
}

bool Game_run(Game* game)
{
    if (!Game_init(game))
        return false;
    game->prev_tick = SDL_GetPerformanceCounter();
    
    while (!game->quit) {
        Uint64 prev_tick = game->prev_tick;
        Uint64 now = SDL_GetPerformanceCounter();

        float delta = (now - prev_tick) / (float)game->perf_freq;
        
        if (delta >= (TICK_DURATION)) {
            game->prev_tick = now;
            handle_events(game);
            SceneInterface current_scene = game->current_scene;

            if (!current_scene.vtab->update(current_scene.scene, delta)) return false;
            // if level has been changed, it's update func has to be called before draw func. so skip this until next frame
            if (game->current_scene.scene == current_scene.scene) {
                if (!current_scene.vtab->draw(current_scene.scene)) 
                    return false;
            }
            SDL_RenderPresent(game->renderer);
        } else {
            float sleep_time = (float)((TICK_DURATION - delta) * 1000);
            SDL_Delay((Uint32)sleep_time);
        } 
    }
    
    return true;
}

void Game_exit(Game* game)
{
    game->quit = true;
}

void Game_destroy(Game *game) 
{
    destroy_assets();
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);

    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}