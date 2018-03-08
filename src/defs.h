#pragma once

#define LOGICAL_WIDTH 240
#define LOGICAL_HEIGHT 320

#define WINDOW_WIDTH (LOGICAL_WIDTH * 2)
#define WINDOW_HEIGHT (LOGICAL_HEIGHT * 2)

#define TICK_DURATION (1.0/60.0)

#define ARRAYSIZE(arr) (sizeof(arr)/sizeof(*arr))

#define ERR_IF(exp, cond) do {if ((exp) cond) return false;} while(0)

#define MS_TO_Sf(ms) ((float)(ms)/1000.0)

typedef struct Point {
    float x, y;
} Point;