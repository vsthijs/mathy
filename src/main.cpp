#include "assets.hpp"
#include "window.hpp"
#include "raylib.h"
#include <iostream>

const int playerX = 450;
const int playerY = 300;
unsigned int playerSize = 50;
int mouseX, mouseY;

int main(int argc, char** argv) {
    Window win{"mathy", 900, 600};
    // SetTargetFPS(60);
    SetExitKey(KEY_Q);
    // SetTargetFPS(60);
    SetExitKey(KEY_Q);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_W)) playerSize += 1.0f;
        if (IsKeyDown(KEY_S)) playerSize -= 1.0f;
        {
            playerX = GetMouseX();
            playerY = GetMouseY();
        }

        BeginDrawing();
            ClearBackground(WHITE);
            DrawFPS(10, 10);
            DrawTextureEx(assets.require_texture("0.png"),
                          Vector2{playerX, playerY}, 0, playerSize / 10, WHITE);
        EndDrawing();
    }

    return 0;
}
