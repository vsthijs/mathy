#include "window.hpp"
#include "raylib.h"
#include <iostream>

int main() {
    Window win{"mathy", 900, 600};
    // SetTargetFPS(60);
    SetExitKey(KEY_Q);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawFPS(10, 10);
        EndDrawing();
    }

    return 0;
}
