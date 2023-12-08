#include "window.hpp"
#include "raylib.h"
#include <iostream>

const int playerX = 450;
const int playerY = 300;
int playerSize = 50;

int main() {
    Window win{"mathy", 900, 600};
    // SetTargetFPS(60);
    SetExitKey(KEY_Q);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_W)) playerSize += 1.0f;
        if (IsKeyDown(KEY_S)) playerSize -= 1.0f;

        BeginDrawing();
            ClearBackground(WHITE);
            DrawFPS(10, 10);
            DrawCircle(playerX, playerY, playerSize, RED);
        EndDrawing();
    }

    return 0;
}
