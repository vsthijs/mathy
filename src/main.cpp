#include "assets.hpp"
#include "window.hpp"
#include "raylib.h"
#include <iostream>

int playerX = 0;
int playerY = 0;
unsigned int playerSize = 50;
int mouseX, mouseY;

int main(int argc, char** argv) {
    Window win{"mathy", 900, 600};
    AssetManager assets{ASSETS_PATH};

    SetTargetFPS(60);
    SetExitKey(KEY_Q);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_W)) playerSize += 1.0f;
        if (IsKeyDown(KEY_S)) playerSize -= 1.0f;
        if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
        {
            playerX = GetMouseX();
            playerY = GetMouseY();
        }

        BeginDrawing();
            ClearBackground(WHITE);
            DrawFPS(10, 10);
            DrawTextureEx(assets.require_texture("player_front.png"),
                          Vector2{(float)playerX, (float)playerY}, 0, playerSize / 10, WHITE);
        EndDrawing();
    }

    return 0;
}
