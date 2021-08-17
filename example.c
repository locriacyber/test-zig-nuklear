#include "dummy.h"

int main() {
    struct nk_rect r = nk_rect(100, 100, 220, 220);
    nk_print_rect(r);
    return 0;
}
