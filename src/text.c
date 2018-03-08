#include "text.h"
#include <stdbool.h>
#include "assets.h"
#include <inttypes.h>
#include <ctype.h>
#include <stdio.h>

static SDL_Rect *get_char_rect(const char c) 
{
    SDL_Rect *r;
    if (isupper(c)) {
        r = &asset_font_acilis_rects[c - 65];
    } else if (islower(c)) {
        r = &asset_font_acilis_rects[c - 97 + 29];
    } else if (isdigit(c)) {
        r = &asset_font_acilis_rects[c - 48 + 62];
    } else {
        switch (c) {
        case '(': r = &asset_font_acilis_rects[26]; break;
        case ')': r = &asset_font_acilis_rects[27]; break;
        case ':': r = &asset_font_acilis_rects[28]; break;
        case '.': r = &asset_font_acilis_rects[55]; break;
        case ',': r = &asset_font_acilis_rects[56]; break;
        case ';': r = &asset_font_acilis_rects[57]; break;
        case '?': r = &asset_font_acilis_rects[58]; break;
        case '"': r = &asset_font_acilis_rects[59]; break;
        case '\'': r = &asset_font_acilis_rects[60]; break;
        case '-': r = &asset_font_acilis_rects[61]; break;
        case '<': r = &asset_font_acilis_rects[72]; break;
        case '>': r = &asset_font_acilis_rects[73]; break;
        default : r = &asset_font_acilis_rects[74]; break;
        }
    }

    return r;
}

bool text_draw_acilis(const char *text, SDL_Renderer *renderer, SDL_Point pos, int size_factor) 
{
    int x = 0;
    const char *p = text;
    for (;*p != '\0'; p++) {
        SDL_Rect* r = get_char_rect(*p);
        SDL_Rect dst = { pos.x + x, pos.y, r->w * size_factor, r->h * size_factor };

        int res = SDL_RenderCopy(renderer, asset_font_acilis, r, &dst);
        if (res == -1) return false;
        x += r->w * size_factor;
    }

    return true;
}

int text_get_width(const char *text, int size_factor) 
{
    int x = 0;
    const char *p = text;
    for (;*p != '\0'; p++) {
        SDL_Rect* r = get_char_rect(*p);
        x += r->w * size_factor;
    }

    return x;
}

char charbuf[100];

bool text_draw_score(Uint32 num, SDL_Renderer *renderer, SDL_Point pos, int size_factor) 
{
    sprintf(charbuf, "%" PRIu32, num);
    char* p = charbuf;

    int x = 0;
    for (;*p != '\0'; p++) {
        SDL_Rect* r;
        if (isdigit(*p))
            r = &asset_font_score_rects[*p - 48];
        else
            r = &asset_font_score_rects[10];

        SDL_Rect dst = { pos.x + x, pos.y, r->w * size_factor, r->h * size_factor };

        int res = SDL_RenderCopy(renderer, asset_font_score, r, &dst);
        if (res == -1) return false;
        x += r->w * size_factor;
    }

    return true;
}
