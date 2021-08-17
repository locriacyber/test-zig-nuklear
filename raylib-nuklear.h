/**********************************************************************************************
*
*   raylib-nuklear - Nuklear for Raylib.
*
*   FEATURES:
*       - Use the nuklear immediate-mode graphical user interface in raylib.
*
*   DEPENDENCIES:
*       - raylib 3.7 https://www.raylib.com/
*       - nuklear https://github.com/Immediate-Mode-UI/Nuklear
*
*   LICENSE: zlib/libpng
*
*   raylib-nuklear is licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software:
*
*   Copyright (c) 2020 Rob Loach (@RobLoach)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#ifndef RAYLIB_NUKLEAR_H
#define RAYLIB_NUKLEAR_H

#ifndef NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_STANDARD_VARARGS
#endif

#include "nuklear.h"

NK_API struct nk_context* InitNuklear(int fontSize);
NK_API void DumpNuklear(struct nk_context * ctx);

#endif  // RAYLIB_NUKLEAR_H

#ifdef RAYLIB_NUKLEAR_IMPLEMENTATION
#ifndef RAYLIB_NUKLEAR_IMPLEMENTATION_ONCE
#define RAYLIB_NUKLEAR_IMPLEMENTATION_ONCE

#ifndef NK_ASSERT
#define NK_ASSERT(condition) if (!(condition)) { printf("NUKLEAR: Failed assert \"%s\" (%s:%i)\n", #condition, "nuklear.h", __LINE__); }
#endif  // NK_ASSERT

// TODO: Replace NK_INCLUDE_DEFAULT_ALLOCATOR with MemAlloc() and MemFree()
#ifndef NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#endif  // NK_INCLUDE_DEFAULT_ALLOCATOR

#ifndef NK_BOOL
#define NK_INCLUDE_STANDARD_BOOL
#define NK_BOOL bool
#endif  // NK_BOOL

#define NK_IMPLEMENTATION
#include "nuklear.h"

#include <stdio.h>
#include <string.h>

NK_API float
nk_raylib_font_get_text_width(nk_handle handle, float height, const char *text, int len)
{
    NK_UNUSED(handle);
    if (len <= 0) {
        return 0;
    }

    return len * height / 2; // MOCK
}

NK_API struct nk_context*
InitNuklear(int fontSize)
{
    if (fontSize <= 0) fontSize = 20;

    // User font.
    struct nk_user_font* userFont = malloc(sizeof(struct nk_user_font));
    userFont->height = (float)fontSize;
    userFont->width = nk_raylib_font_get_text_width;

    struct nk_context* ctx = malloc(sizeof(struct nk_context));

    // Create the nuklear environment.
    if (nk_init_default(ctx, userFont) == 0) {
        printf("NUKLEAR: Failed to initialize nuklear\n");
        return 0;
    }

    return ctx;
}

NK_API void
DumpNuklear(struct nk_context * ctx)
{
    printf("Commands: ");
    const struct nk_command *cmd;
    nk_foreach(cmd, ctx) {
        printf("%d, ", cmd->type);
    }
    printf("\n");
}

#endif // RAYLIB_NUKLEAR_IMPLEMENTATION_ONCE
#endif // RAYLIB_NUKLEAR_IMPLEMENTATION
