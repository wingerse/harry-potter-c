#include "assets.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>

#include "../obj/res/font-acilis.png.h"
#include "../obj/res/scoreFont.png.h"
#include "../obj/res/backgroundBoard.png.h"
#include "../obj/res/castleBoard.png.h"
#include "../obj/res/skyBoard.png.h"
#include "../obj/res/groundUnitBoard.png.h"
#include "../obj/res/magicBoard.png.h"
#include "../obj/res/acilis.jpg.h"
#include "../obj/res/bg2.png.h"
#include "../obj/res/button-off.png.h"
#include "../obj/res/button-over.png.h"
#include "../obj/res/button-over-ex.png.h"
#include "../obj/res/harry.png.h"
#include "../obj/res/magic.png.h"
#include "../obj/res/playerExplosion.png.h"
#include "../obj/res/obstacle1.png.h"
#include "../obj/res/obstacle2.png.h"
#include "../obj/res/obstacle3.png.h"
#include "../obj/res/obstacle4.png.h"
#include "../obj/res/obstacle5.png.h"
#include "../obj/res/obstacle6.png.h"
#include "../obj/res/obstacle7.png.h"
#include "../obj/res/obstacle8.png.h"
#include "../obj/res/obstacle9.png.h"
#include "../obj/res/obstacle10.png.h"
#include "../obj/res/obstacle11.png.h"
#include "../obj/res/obstacle12.png.h"
#include "../obj/res/obstacle13.png.h"
#include "../obj/res/obstacle14.png.h"
#include "../obj/res/obstacle15.png.h"
#include "../obj/res/music.mp3.h"


SDL_Texture* asset_font_acilis;
SDL_Rect asset_font_acilis_rects[75] = {
    {0, 0, 12, 16}, {12, 0, 10, 16}, {22, 0, 10, 16}, {32, 0, 13, 16}, {45, 0, 9, 16}, {54, 0, 11, 16}, 
    {65, 0, 11, 16}, {76, 0, 12, 16}, {88, 0, 6, 16}, {94, 0, 6, 16}, {100, 0, 11, 16}, {111, 0, 8, 16}, 
    {119, 0, 13, 16}, {132, 0, 11, 16}, {143, 0, 12, 16}, {155, 0, 11, 16}, {0, 16, 12, 16}, {12, 16, 13, 16}, 
    {25, 16, 10, 16}, {35, 16, 13, 16}, {48, 16, 11, 16}, {59, 16, 16, 16}, {75, 16, 18, 16}, {93, 16, 13, 16}, 
    {106, 16, 13, 16}, {119, 16, 12, 16}, {131, 16, 6, 16}, {140, 16, 7, 16}, {147, 16, 5, 16}, {1, 32, 8, 16}, 
    {11, 32, 7, 16}, {20, 32, 7, 16}, {28, 32, 10, 16}, {39, 32, 8, 16}, {48, 32, 8, 16}, {57, 32, 8, 16}, 
    {67, 32, 8, 16}, {77, 32, 4, 16}, {82, 32, 4, 16}, {88, 32, 8, 16}, {97, 32, 6, 16}, {105, 32, 9, 16}, 
    {116, 32, 8, 16}, {125, 32, 9, 16}, {135, 32, 9, 16}, {146, 32, 9, 16}, {156, 32, 8, 16}, {0, 48, 8, 16}, 
    {8, 48, 10, 16}, {19, 48, 8, 16}, {29, 48, 10, 16}, {42, 48, 14, 16}, {57, 48, 10, 16}, {69, 48, 9, 16}, 
    {80, 48, 9, 16}, {91, 48, 4, 16}, {97, 48, 3, 16}, {102, 48, 5, 16}, {109, 48, 8, 16}, {119, 48, 6, 16}, 
    {127, 48, 4, 16}, {131, 48, 8, 16}, {0, 64, 9, 16}, {12, 64, 5, 16}, {18, 64, 10, 16}, {29, 64, 9, 16}, 
    {39, 64, 10, 16}, {52, 64, 8, 16}, {61, 64, 9, 16}, {70, 64, 9, 16}, {79, 64, 9, 16}, {89, 64, 11, 16}, 
    {117, 64, 5, 16}, {122, 64, 7, 16}, {157, 64, 4, 16}
};

SDL_Texture* asset_font_score;
SDL_Rect asset_font_score_rects[11] = {
    { 0, 0, 10, 13 }, { 11, 0, 6, 13 }, { 18, 0, 8, 13 }, { 28, 0, 10, 13 },
    { 40, 0, 9, 13 }, { 51, 0, 8, 13 }, { 61, 0, 8, 13 }, { 70, 0, 8, 13 },
    { 80, 0, 8, 13 }, { 88, 0, 9, 13 }, { 97, 0, 9, 13 }
};

SDL_Texture* asset_background_board;
SDL_Texture* asset_castle_board;
SDL_Texture* asset_sky_board;
SDL_Texture* asset_ground_unit_board;
SDL_Texture* asset_magic_board;

SDL_Texture* asset_acilis;
SDL_Texture* asset_bg2;
SDL_Texture* asset_button_off;
SDL_Texture* asset_button_over;
SDL_Texture* asset_button_over_ex;
SDL_Texture* asset_harry;
SDL_Texture* asset_magic;
SDL_Texture* asset_explosion;

SDL_Texture* asset_obstacle1;
SDL_Texture* asset_obstacle2;
SDL_Texture* asset_obstacle3;
SDL_Texture* asset_obstacle4;
SDL_Texture* asset_obstacle5;
SDL_Texture* asset_obstacle6;
SDL_Texture* asset_obstacle7;
SDL_Texture* asset_obstacle8;
SDL_Texture* asset_obstacle9;
SDL_Texture* asset_obstacle10;
SDL_Texture* asset_obstacle11;
SDL_Texture* asset_obstacle12;
SDL_Texture* asset_obstacle13;
SDL_Texture* asset_obstacle14;
SDL_Texture* asset_obstacle15;

Mix_Music* asset_music;

static SDL_Texture* load_texture(const void *mem, size_t size, SDL_Renderer* renderer)
{
    SDL_RWops *rw = SDL_RWFromConstMem(mem, (int)size);
    SDL_Surface* surface = IMG_Load_RW(rw, 1);
    if (!surface)
        return NULL;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

bool load_assets(SDL_Renderer* renderer)
{
    asset_font_score = load_texture(res_scoreFont_png, sizeof(res_scoreFont_png), renderer);
    if (asset_font_score == NULL)
        return false;
    asset_font_acilis = load_texture(res_font_acilis_png, sizeof(res_font_acilis_png), renderer);
    if (asset_font_acilis == NULL)
        return false;

    asset_background_board = load_texture(res_backgroundBoard_png, sizeof(res_backgroundBoard_png), renderer);
    if (asset_background_board == NULL)
        return false;
    asset_castle_board = load_texture(res_castleBoard_png, sizeof(res_castleBoard_png), renderer);
    if (asset_castle_board == NULL)
        return false;
    asset_sky_board = load_texture(res_skyBoard_png, sizeof(res_skyBoard_png), renderer);
    if (asset_sky_board == NULL)
        return false;
    asset_ground_unit_board = load_texture(res_groundUnitBoard_png, sizeof(res_groundUnitBoard_png), renderer);
    if (asset_ground_unit_board == NULL)
        return false;
    asset_magic_board = load_texture(res_magicBoard_png, sizeof(res_magicBoard_png), renderer);
    if (asset_magic_board == NULL)
        return false;

    asset_acilis = load_texture(res_acilis_jpg, sizeof(res_acilis_jpg), renderer);
    if (asset_acilis == NULL)
        return false;
    asset_bg2 = load_texture(res_bg2_png, sizeof(res_bg2_png), renderer);
    if (asset_bg2 == NULL)
        return false;
    asset_button_off = load_texture(res_button_off_png, sizeof(res_button_off_png), renderer);
    if (asset_button_off == NULL)
        return false;
    asset_button_over = load_texture(res_button_over_png, sizeof(res_button_over_png), renderer);
    if (asset_button_over == NULL)
        return false;
    asset_button_over_ex = load_texture(res_button_over_ex_png, sizeof(res_button_over_ex_png), renderer);
    if (asset_button_over_ex == NULL)
        return false;
    asset_harry = load_texture(res_harry_png, sizeof(res_harry_png), renderer);
    if (asset_harry == NULL)
        return false;
    asset_magic = load_texture(res_magic_png, sizeof(res_magic_png), renderer);
    if (asset_magic == NULL)
        return false;
    asset_explosion = load_texture(res_playerExplosion_png, sizeof(res_playerExplosion_png), renderer);
    if (asset_explosion == NULL)
        return false;

    asset_obstacle1 = load_texture(res_obstacle1_png, sizeof(res_obstacle1_png), renderer);
    if (asset_obstacle1 == NULL)
        return false;
    asset_obstacle2 = load_texture(res_obstacle2_png, sizeof(res_obstacle2_png), renderer);
    if (asset_obstacle2 == NULL)
        return false;
    asset_obstacle3 = load_texture(res_obstacle3_png, sizeof(res_obstacle3_png), renderer);
    if (asset_obstacle3 == NULL)
        return false;
    asset_obstacle4 = load_texture(res_obstacle4_png, sizeof(res_obstacle4_png), renderer);
    if (asset_obstacle4 == NULL)
        return false;
    asset_obstacle5 = load_texture(res_obstacle5_png, sizeof(res_obstacle5_png), renderer);
    if (asset_obstacle5 == NULL)
        return false;
    asset_obstacle6 = load_texture(res_obstacle6_png, sizeof(res_obstacle6_png), renderer);
    if (asset_obstacle6 == NULL)
        return false;
    asset_obstacle7 = load_texture(res_obstacle7_png, sizeof(res_obstacle7_png), renderer);
    if (asset_obstacle7 == NULL)
        return false;
    asset_obstacle8 = load_texture(res_obstacle8_png, sizeof(res_obstacle8_png), renderer);
    if (asset_obstacle8 == NULL)
        return false;
    asset_obstacle9 = load_texture(res_obstacle9_png, sizeof(res_obstacle9_png), renderer);
    if (asset_obstacle9 == NULL)
        return false;
    asset_obstacle10 = load_texture(res_obstacle10_png, sizeof(res_obstacle10_png), renderer);
    if (asset_obstacle10 == NULL)
        return false;
    asset_obstacle11 = load_texture(res_obstacle11_png, sizeof(res_obstacle11_png), renderer);
    if (asset_obstacle11 == NULL)
        return false;
    asset_obstacle12 = load_texture(res_obstacle12_png, sizeof(res_obstacle12_png), renderer);
    if (asset_obstacle12 == NULL)
        return false;
    asset_obstacle13 = load_texture(res_obstacle13_png, sizeof(res_obstacle13_png), renderer);
    if (asset_obstacle13 == NULL)
        return false;
    asset_obstacle14 = load_texture(res_obstacle14_png, sizeof(res_obstacle14_png), renderer);
    if (asset_obstacle14 == NULL)
        return false;
    asset_obstacle15 = load_texture(res_obstacle15_png, sizeof(res_obstacle15_png), renderer);
    if (asset_obstacle15 == NULL)
        return false;

    asset_music = Mix_LoadMUS_RW(SDL_RWFromConstMem(res_music_mp3, sizeof(res_music_mp3)), 1);
    if (asset_music == NULL)
        return false;
    return true;
}

void destroy_assets() 
{
    SDL_DestroyTexture(asset_font_acilis);
    SDL_DestroyTexture(asset_font_score);

    SDL_DestroyTexture(asset_background_board);
    SDL_DestroyTexture(asset_castle_board);
    SDL_DestroyTexture(asset_sky_board);
    SDL_DestroyTexture(asset_ground_unit_board);
    SDL_DestroyTexture(asset_magic_board);

    SDL_DestroyTexture(asset_acilis);
    SDL_DestroyTexture(asset_bg2);
    SDL_DestroyTexture(asset_button_off);
    SDL_DestroyTexture(asset_button_over);
    SDL_DestroyTexture(asset_button_over_ex);
    SDL_DestroyTexture(asset_harry);
    SDL_DestroyTexture(asset_magic);
    SDL_DestroyTexture(asset_explosion);

    SDL_DestroyTexture(asset_obstacle1);
    SDL_DestroyTexture(asset_obstacle2);
    SDL_DestroyTexture(asset_obstacle3);
    SDL_DestroyTexture(asset_obstacle4);
    SDL_DestroyTexture(asset_obstacle5);
    SDL_DestroyTexture(asset_obstacle6);
    SDL_DestroyTexture(asset_obstacle7);
    SDL_DestroyTexture(asset_obstacle8);
    SDL_DestroyTexture(asset_obstacle9);
    SDL_DestroyTexture(asset_obstacle10);
    SDL_DestroyTexture(asset_obstacle11);
    SDL_DestroyTexture(asset_obstacle12);
    SDL_DestroyTexture(asset_obstacle13);
    SDL_DestroyTexture(asset_obstacle14);
    SDL_DestroyTexture(asset_obstacle15);

    Mix_FreeMusic(asset_music);
}

