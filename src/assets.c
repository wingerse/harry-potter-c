#include "assets.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdbool.h>

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

static SDL_Texture* load_texture(const char* path, SDL_Renderer* renderer)
{
    SDL_Surface* surface = IMG_Load(path);
    if (!surface)
        return NULL;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

bool load_assets(SDL_Renderer* renderer)
{
    asset_font_acilis = load_texture("res/font-acilis.png", renderer);
    if (asset_font_acilis == NULL)
        return false;
    asset_font_score = load_texture("res/scoreFont.png", renderer);
    if (asset_font_score == NULL)
        return false;

    asset_background_board = load_texture("res/backgroundBoard.png", renderer);
    if (asset_background_board == NULL)
        return false;
    asset_castle_board = load_texture("res/castleBoard.png", renderer);
    if (asset_castle_board == NULL)
        return false;
    asset_sky_board = load_texture("res/skyBoard.png", renderer);
    if (asset_sky_board == NULL)
        return false;
    asset_ground_unit_board = load_texture("res/groundUnitBoard.png", renderer);
    if (asset_ground_unit_board == NULL)
        return false;
    asset_magic_board = load_texture("res/magicBoard.png", renderer);
    if (asset_magic_board == NULL)
        return false;

    asset_acilis = load_texture("res/acilis.jpg", renderer);
    if (asset_acilis == NULL)
        return false;
    asset_bg2 = load_texture("res/bg2.png", renderer);
    if (asset_bg2 == NULL)
        return false;
    asset_button_off = load_texture("res/button-off.png", renderer);
    if (asset_button_off == NULL)
        return false;
    asset_button_over = load_texture("res/button-over.png", renderer);
    if (asset_button_over == NULL)
        return false;
    asset_button_over_ex = load_texture("res/button-over-ex.png", renderer);
    if (asset_button_over_ex == NULL)
        return false;
    asset_harry = load_texture("res/harry.png", renderer);
    if (asset_harry == NULL)
        return false;
    asset_magic = load_texture("res/magic.png", renderer);
    if (asset_magic == NULL)
        return false;
    asset_explosion = load_texture("res/playerExplosion.png", renderer);
    if (asset_explosion == NULL)
        return false;

    asset_obstacle1 = load_texture("res/obstacle1.png", renderer);
    if (asset_obstacle1 == NULL)
        return false;
    asset_obstacle2 = load_texture("res/obstacle2.png", renderer);
    if (asset_obstacle2 == NULL)
        return false;
    asset_obstacle3 = load_texture("res/obstacle3.png", renderer);
    if (asset_obstacle3 == NULL)
        return false;
    asset_obstacle4 = load_texture("res/obstacle4.png", renderer);
    if (asset_obstacle4 == NULL)
        return false;
    asset_obstacle5 = load_texture("res/obstacle5.png", renderer);
    if (asset_obstacle5 == NULL)
        return false;
    asset_obstacle6 = load_texture("res/obstacle6.png", renderer);
    if (asset_obstacle6 == NULL)
        return false;
    asset_obstacle7 = load_texture("res/obstacle7.png", renderer);
    if (asset_obstacle7 == NULL)
        return false;
    asset_obstacle8 = load_texture("res/obstacle8.png", renderer);
    if (asset_obstacle8 == NULL)
        return false;
    asset_obstacle9 = load_texture("res/obstacle9.png", renderer);
    if (asset_obstacle9 == NULL)
        return false;
    asset_obstacle10 = load_texture("res/obstacle10.png", renderer);
    if (asset_obstacle10 == NULL)
        return false;
    asset_obstacle11 = load_texture("res/obstacle11.png", renderer);
    if (asset_obstacle11 == NULL)
        return false;
    asset_obstacle12 = load_texture("res/obstacle12.png", renderer);
    if (asset_obstacle12 == NULL)
        return false;
    asset_obstacle13 = load_texture("res/obstacle13.png", renderer);
    if (asset_obstacle13 == NULL)
        return false;
    asset_obstacle14 = load_texture("res/obstacle14.png", renderer);
    if (asset_obstacle14 == NULL)
        return false;
    asset_obstacle15 = load_texture("res/obstacle15.png", renderer);
    if (asset_obstacle15 == NULL)
        return false;

    asset_music = Mix_LoadMUS("res/music.mp3");
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

