#include "startmenu.h"
#include "assets.h"
#include "deathmenu.h"
#include "mainlevel.h"
#include "game.h"
#include "scene.h"
#include "text.h"
#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include "keypress.h"
#include "defs.h"
#include "collision.h"

SceneInterface_vtab StartMenu_SceneInterface_vtab = { StartMenu_update, StartMenu_draw };

void StartMenu_reset(StartMenu *start_menu, Game *game)
{
    start_menu->game = game;
    start_menu->pos = StartMenuPos_Start;
}

bool StartMenu_update(void* scene, float delta)
{
    StartMenu* this = scene;

    if (key_pressed(SDL_SCANCODE_UP) || key_pressed(SDL_SCANCODE_DOWN)) {
        if (this->pos == StartMenuPos_Start)
            this->pos = StartMenuPos_Exit;
        else 
            this->pos = StartMenuPos_Start;
    }

    if (key_pressed(SDL_SCANCODE_RETURN)) {
        if (this->pos == StartMenuPos_Exit) {
            Game_exit(this->game);
        } else {
            MainLevel_reset(&main_level, this->game);
            this->game->current_scene = (SceneInterface){&main_level, &MainLevel_SceneInterface_vtab};
        }
    }

    return true;
}

bool StartMenu_draw(void* scene)
{
    StartMenu* this = scene;
    ERR_IF(SDL_RenderCopy(this->game->renderer, asset_acilis, NULL, NULL), == -1);
    
    int pointer_x = 145, pointer_y;
    if (this->pos == StartMenuPos_Start) {
        pointer_y = 230;
    } else {
        pointer_y = 250;
    }

    int w, h;
    SDL_QueryTexture(asset_button_over_ex, NULL, NULL, &w, &h);

    ERR_IF(SDL_RenderCopy(this->game->renderer, asset_button_over_ex, NULL, &(SDL_Rect){pointer_x, pointer_y, w, h}), == -1);

    ERR_IF(text_draw_acilis("Start game", this->game->renderer, (SDL_Point){145, 230}, 1), == false);
    ERR_IF(text_draw_acilis("Exit", this->game->renderer, (SDL_Point){145, 250}, 1), == false); 
    
    return true;
}
