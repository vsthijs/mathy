#include "window.hpp"
#include "raylib.h"
#include <iostream>

int playerX = 450;
int playerY = 300;
int playerSize = 50;
int mouseX;
int mouseY;

int main() {
    Window win{"mathy", 900, 600};
    SetTargetFPS(60);
    SetExitKey(KEY_Q);

    while (!WindowShouldClose()) {

        if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
        {
            playerX = GetMouseX();
            playerY = GetMouseY();
        }

        BeginDrawing();
            ClearBackground(WHITE);
            DrawFPS(10, 10);
            DrawCircle(playerX, playerY, playerSize, RED);
        EndDrawing();
    }

    return 0;
}
