#pragma once

#include <SDL.h>
#include <stdbool.h>

typedef struct SceneInterface_vtab {
    bool (*update)(void *scene, float delta);
    bool (*draw)(void *scene);
} SceneInterface_vtab;

typedef struct SceneInterface {
    void *scene;
    SceneInterface_vtab *vtab;
} SceneInterface;