usingnamespace @cImport({
    @cInclude("dummy.h");
});

pub fn main() void {
    const r = nk_rect(100, 100, 220, 220);
    nk_print_rect(r);
}
