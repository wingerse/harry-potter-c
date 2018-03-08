#pragma once

#include <SDL.h>
#include <stdbool.h>

extern char charbuf[100];

bool text_draw_acilis(const char *text, SDL_Renderer *renderer, SDL_Point pos, int size_factor);
int text_get_width(const char *text, int size_factor);
bool text_draw_score(Uint32 num, SDL_Renderer *renderer, SDL_Point pos, int size_factor);