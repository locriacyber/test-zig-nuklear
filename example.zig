const std = @import("std");
usingnamespace @cImport({
    @cInclude("raylib-nuklear.h");
});

const fontSize = 12;

pub fn main() anyerror!void {
    InitWindow(640, 480, "Hello world");
    defer CloseWindow();
    const ctx: *nk_context = InitNuklear(fontSize);
    defer UnloadNuklear(ctx);

    while (!WindowShouldClose()) {
        UpdateNuklear(ctx);
        if (nk_begin(ctx, "Nuklear", nk_rect(100, 100, 220, 220), NK_WINDOW_BORDER | NK_WINDOW_MOVABLE | NK_WINDOW_CLOSABLE) != 0) {
            nk_layout_row_static(ctx, 30, 80, 1);
            if (nk_button_label(ctx, "Button") != 0) {
                std.log.info("button clicked", .{});
            }
        }
        nk_end(ctx);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawNuklear(ctx);
        DrawRectangle(0, 0, 100, 100, BLACK);
        EndDrawing();
    }
}
