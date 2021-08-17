#ifndef DUMMY_H
#define DUMMY_H

struct nk_rect {float x,y,w,h;};
struct nk_rect nk_rect(float x, float y, float w, float h);
void nk_print_rect(struct nk_rect bounds);

#endif

#ifdef DUMMY_IMPL

#include <stdio.h>

struct nk_rect nk_rect(float x, float y, float w, float h)
{
    struct nk_rect r;
    r.x = x; r.y = y;
    r.w = w; r.h = h;
    return r;
}

void nk_print_rect(struct nk_rect bounds)
{
    printf("bounds.x = %f\n", bounds.x);
    printf("bounds.y = %f\n", bounds.y);
    printf("bounds.w = %f\n", bounds.w);
    printf("bounds.h = %f\n", bounds.h);
}
#endif