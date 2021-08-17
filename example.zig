usingnamespace @cImport({
    @cInclude("raylib-nuklear.h");
});

pub fn main() void {
    const ctx: [*c]nk_context = InitNuklear(10);
    DumpNuklear(ctx);
    _ = nk_begin(ctx, "Nuklear", nk_rect(100, 100, 220, 220), NK_WINDOW_BORDER | NK_WINDOW_MOVABLE | NK_WINDOW_CLOSABLE);
    DumpNuklear(ctx);
    nk_end(ctx);
    DumpNuklear(ctx);
}
