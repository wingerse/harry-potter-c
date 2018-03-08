#pragma once

#include <SDL.h>
#include "scene.h"
#include <stdbool.h>

typedef struct Game Game;

typedef enum StartMenuPos {
    StartMenuPos_Start,
    StartMenuPos_Exit
} StartMenuPos;

typedef struct StartMenu {
    StartMenuPos pos;
    Game *game;
} StartMenu;

extern SceneInterface_vtab StartMenu_SceneInterface_vtab;

void StartMenu_reset(StartMenu *start_menu, Game *game);
bool StartMenu_update(void *scene, float delta);
bool StartMenu_draw(void *scene);