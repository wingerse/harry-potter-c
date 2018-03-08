#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <stdbool.h>

extern SDL_Texture* asset_font_acilis;
extern SDL_Rect asset_font_acilis_rects[75];

extern SDL_Texture* asset_font_score;
extern SDL_Rect asset_font_score_rects[11];

extern SDL_Texture* asset_background_board;
extern SDL_Texture* asset_castle_board;
extern SDL_Texture* asset_sky_board;
extern SDL_Texture* asset_ground_unit_board;
extern SDL_Texture* asset_magic_board;

extern SDL_Texture* asset_acilis;
extern SDL_Texture* asset_bg2;
extern SDL_Texture* asset_button_off;
extern SDL_Texture* asset_button_over;
extern SDL_Texture* asset_button_over_ex;
extern SDL_Texture* asset_harry;
extern SDL_Texture* asset_magic;
extern SDL_Texture* asset_explosion;

extern SDL_Texture* asset_obstacle1;
extern SDL_Texture* asset_obstacle2;
extern SDL_Texture* asset_obstacle3;
extern SDL_Texture* asset_obstacle4;
extern SDL_Texture* asset_obstacle5;
extern SDL_Texture* asset_obstacle6;
extern SDL_Texture* asset_obstacle7;
extern SDL_Texture* asset_obstacle8;
extern SDL_Texture* asset_obstacle9;
extern SDL_Texture* asset_obstacle10;
extern SDL_Texture* asset_obstacle11;
extern SDL_Texture* asset_obstacle12;
extern SDL_Texture* asset_obstacle13;
extern SDL_Texture* asset_obstacle14;
extern SDL_Texture* asset_obstacle15;

extern Mix_Music* asset_music;

bool load_assets(SDL_Renderer* renderer);
void destroy_assets();