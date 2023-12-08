#include "assets.hpp"
#include "window.hpp"
#include "raylib.h"
#include <iostream>

const int playerX = 450;
const int playerY = 300;
unsigned int playerSize = 50;

int main(int argc, char** argv) {
    Window win{"mathy", 900, 600};
    AssetManager assets{ASSETS_PATH};

    // SetTargetFPS(60);
    SetExitKey(KEY_Q);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_W)) playerSize += 1;
        if (IsKeyDown(KEY_S) && playerSize > 0) playerSize -= 1;

        BeginDrawing();
            ClearBackground(WHITE);
            DrawFPS(10, 10);
            DrawTextureEx(assets.require_texture("0.png"),
                          Vector2{playerX, playerY}, 0, playerSize / 10, WHITE);
        EndDrawing();
    }

    return 0;
}
