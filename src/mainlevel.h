#pragma once

#include "SDL.h"
#include <stdbool.h>
#include "scene.h"
#include "harry.h"
#include "background.h"
#include "map.h"

typedef struct Game Game;

typedef struct MainLevel {
    Harry harry;
    Magic magic;
    bool magic_inited;
    Game* game;

    Background sky;
    Background castle;
    Background magic1;
    Background magic2;

    Map map1;
    Map map2;
} MainLevel;

void MainLevel_reset(MainLevel* m, Game* game);
bool MainLevel_update(void* scene, float delta);
bool MainLevel_draw(void* scene);

extern SceneInterface_vtab MainLevel_SceneInterface_vtab;