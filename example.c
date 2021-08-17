#include "raylib-nuklear.h"

int main() {
    struct nk_context *ctx = InitNuklear(10);

    nk_begin(ctx, "Nuklear", nk_rect(100, 100, 220, 220), NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_CLOSABLE);
    
    nk_end(ctx);
    DumpNuklear(ctx);

    return 0;
}