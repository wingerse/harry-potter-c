#pragma once

typedef struct Vec {
    int x, y;
} Vec;

Vec Vec_negate(Vec a);
Vec Vec_add(Vec a, Vec b);
Vec Vec_sub(Vec a, Vec b);
Vec Vec_mul(Vec a, int scale);
int Vec_dot(Vec a, Vec b);
int Vec_len_squared(Vec a);
double Vec_len(Vec a);
double Vec_angle(Vec a, Vec b);
