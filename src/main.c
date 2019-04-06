#include "game.h"
#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
	Game game;
    if (!Game_run(&game)) {
        fprintf(stderr, "An error occured: %s", SDL_GetError());
        return 1;
    }
    Game_destroy(&game);
    return 0;
}