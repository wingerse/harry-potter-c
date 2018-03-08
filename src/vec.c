#include "vec.h"
#include <math.h>

Vec Vec_negate(Vec a)
{
    return (Vec){ -a.x, -a.y };
}

Vec Vec_add(Vec a, Vec b)
{
    return (Vec){ a.x + b.x, a.y + b.y };
}

Vec Vec_sub(Vec a, Vec b)
{
    return Vec_add(a, Vec_negate(b));
}

Vec Vec_mul(Vec a, int scale)
{
    return (Vec){ a.x * scale, a.y * scale };
}

int Vec_dot(Vec a, Vec b)
{
    return a.x * b.x + a.y * b.y;
}

int Vec_len_squared(Vec a)
{
    return a.x * a.x + a.y * a.y;
}

double Vec_len(Vec a)
{
    return sqrt(Vec_len_squared(a));
}

double Vec_angle(Vec a, Vec b)
{
    return acos((double)Vec_dot(a, b) / (Vec_len(a) * Vec_len(b)));
}
