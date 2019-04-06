#include "keypress.h"
#include <SDL2/SDL.h>
#include <stdbool.h>

bool keypress[SDL_NUM_SCANCODES];

bool key_pressed(SDL_Scancode key)
{
    const Uint8* keyboardstate = SDL_GetKeyboardState(NULL);
    bool current_state = keyboardstate[key];
    bool previous_state = keypress[key];
    keypress[key] = current_state;
    
    return current_state && !previous_state;
}
