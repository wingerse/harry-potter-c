#include "background.h"
#include "defs.h"
#include "math.h"

void Background_init(Background* bg, SDL_Texture* texture, int y, int speed, int images_needed)
{
    bg->texture = texture;  
    bg->y = y;
    bg->speed = speed;
    bg->images_needed = images_needed;

    SDL_QueryTexture(bg->texture, NULL, NULL, &bg->w, &bg->h);
    bg->x = 0;
}

bool Background_update(Background* bg, float delta)
{
    bg->x -= (bg->speed * delta);
    if (bg->x < -bg->w) 
        bg->x = 0;
    return true;
}

bool Background_draw(Background* bg, SDL_Renderer* renderer)
{
    for (int i = 0; i < bg->images_needed; i++) {
        ERR_IF(SDL_RenderCopy(renderer, bg->texture, NULL, &(SDL_Rect){(int)(bg->x) + i * bg->w, bg->y, bg->w, bg->h}), == -1);
    }

    return true;
}
