#pragma once

#include "scene.h"
#include <stdbool.h>
#include <SDL2/SDL.h>

typedef struct Game Game;

typedef enum DeathMenuPos {
    DeathMenuPos_Restart,
    DeathMenuPos_StartMenu,
} DeathMenuPos;

typedef struct DeathMenu {
    int score;
    DeathMenuPos pos;
    Game* game;
} DeathMenu;

void DeathMenu_reset(DeathMenu* death_menu, Game *game, int score);
bool DeathMenu_update(void* scene, float delta);
bool DeathMenu_draw(void *scene);

extern SceneInterface_vtab DeathMenu_SceneInterface_vtab;