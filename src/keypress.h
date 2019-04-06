#pragma once 

#include <SDL2/SDL.h>
#include <stdbool.h>

extern bool keypress[SDL_NUM_SCANCODES];

bool key_pressed(SDL_Scancode key);