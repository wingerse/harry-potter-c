#include "deathmenu.h"
#include "scene.h"
#include "assets.h"
#include "game.h"
#include "text.h"
#include "defs.h"
#include <SDL.h>
#include <stdio.h>
#include "keypress.h"
#include "startmenu.h"
#include "mainlevel.h"

void DeathMenu_reset(DeathMenu* death_menu, Game *game, int score)
{
    death_menu->game = game;
    death_menu->score = score;
    death_menu->pos = DeathMenuPos_Restart;
}

bool DeathMenu_update(void* scene, float delta)
{
    DeathMenu* this = scene;
    if (key_pressed(SDL_SCANCODE_UP) || key_pressed(SDL_SCANCODE_DOWN)) {
        if (this->pos == DeathMenuPos_Restart)
            this->pos = DeathMenuPos_StartMenu;
        else 
            this->pos = DeathMenuPos_Restart;
    }

    if (key_pressed(SDL_SCANCODE_RETURN)) {
        if (this->pos == DeathMenuPos_Restart) {
            MainLevel_reset(&main_level, this->game);
            this->game->current_scene = (SceneInterface){&main_level, &MainLevel_SceneInterface_vtab};
        } else {
            StartMenu_reset(&start_menu, this->game);
            this->game->current_scene = (SceneInterface){&start_menu, &StartMenu_SceneInterface_vtab};
        }
    }

    return true;
}

bool DeathMenu_draw(void *scene)
{
    DeathMenu* this = scene;
    ERR_IF(SDL_RenderCopy(this->game->renderer, asset_background_board, NULL, NULL), == -1);
    
    sprintf(charbuf, "Your score: %d", this->score);
    int width = text_get_width(charbuf, 1);
    ERR_IF(text_draw_acilis(charbuf, this->game->renderer, (SDL_Point){(LOGICAL_WIDTH - width) / 2, 70}, 1), == false);

    const char* restart = "Restart";
    const int restart_width = text_get_width(restart, 1);
    const int restart_x = (LOGICAL_WIDTH - restart_width) / 2;
    const int restart_y = 130;
    const char* startmenu = "Start Menu";
    const int startmenu_width = text_get_width(startmenu, 1);
    const int startmenu_x = (LOGICAL_WIDTH - startmenu_width) / 2;
    const int startmenu_y = 170;

    int button_off_w, button_off_h;
    SDL_QueryTexture(asset_button_off, NULL, NULL, &button_off_w, &button_off_h);
    int button_over_w, button_over_h;
    SDL_QueryTexture(asset_button_over, NULL, NULL, &button_over_w, &button_over_h);

    ERR_IF(SDL_RenderCopy(this->game->renderer, asset_button_off, NULL, &(SDL_Rect){15, restart_y - 25, button_off_w, button_off_h}), == -1);
    ERR_IF(SDL_RenderCopy(this->game->renderer, asset_button_off, NULL, &(SDL_Rect){15, startmenu_y - 25, button_off_w, button_off_h}), == -1);

    int button_over_y;
    switch(this->pos) {
    case DeathMenuPos_Restart: button_over_y = restart_y; break;
    case DeathMenuPos_StartMenu: button_over_y = startmenu_y; break;
    }

    ERR_IF(SDL_RenderCopy(this->game->renderer, asset_button_over, NULL, &(SDL_Rect){15, button_over_y - 25, button_over_w, button_over_h}), == -1);

    ERR_IF(text_draw_acilis(restart, this->game->renderer, (SDL_Point){restart_x, 130}, 1), == false);
    ERR_IF(text_draw_acilis(startmenu, this->game->renderer, (SDL_Point){startmenu_x, 170}, 1), == false);
    return true;
}

SceneInterface_vtab DeathMenu_SceneInterface_vtab = {DeathMenu_update, DeathMenu_draw};