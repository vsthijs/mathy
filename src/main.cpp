#include "assets.hpp"
#include "window.hpp"
#include "raylib.h"
#include <iostream>

int playerX = 450;
int playerY = 300;
unsigned int playerSize = 50;
int mouseX, mouseY;

int main(int argc, char** argv) {
    Window win{"mathy", 900, 600};
    AssetManager assets{ASSETS_PATH};

    SetTargetFPS(60);
    SetExitKey(KEY_Q);

    while (!WindowShouldClose()) {
        //code for the movement player
        if (IsKeyDown(KEY_W)) playerY -= 2.0f; //going up
        if (IsKeyDown(KEY_S)) playerY += 2.0f; //going down
        if (IsKeyDown(KEY_A)) playerX -= 2.0f; //moving left
        if (IsKeyDown(KEY_D)) playerX += 2.0f; //moving right


        BeginDrawing();
            ClearBackground(WHITE);
            DrawFPS(10, 10);
            DrawRectangle(playerX, playerY, 50, 100, BLUE); //drawing the player
            DrawRectangle(200, 300, 70, 90, RED); //drawing the quest giver
            //DrawTextureEx(assets.require_texture("player_front.png"),
            //              Vector2{(float)playerX, (float)playerY}, 0, playerSize / 10, WHITE);
        EndDrawing();
    }

    return 0;
}
