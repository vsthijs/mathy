#include "assets.hpp"
#include "window.hpp"
#include "raylib.h"
#include <iostream>

//unsigned int playerSize = 50;
//int mouseX, mouseY;

struct Player
{
    float x, y;
    int width, height;

    void Draw()
    {
        DrawRectangle(x, y, width, height, BLUE);
    }
};

int main(int argc, char** argv) {
    Window win{"mathy", 900, 600};
    AssetManager assets{ASSETS_PATH};

    //setting player variables
    Player player;
    player.x = 450;
    player.y = 300;
    player.width = 60;
    player.height = 100;

    SetTargetFPS(60);
    SetExitKey(KEY_Q);

    while (!WindowShouldClose()) {
        //code for the movement player
        if (IsKeyDown(KEY_W)) player.y -= 2.0f; //going up
        if (IsKeyDown(KEY_S)) player.y += 2.0f; //going down
        if (IsKeyDown(KEY_A)) player.x -= 2.0f; //moving left
        if (IsKeyDown(KEY_D)) player.x += 2.0f; //moving right


        BeginDrawing();
            ClearBackground(WHITE);
            DrawFPS(10, 10);
            player.Draw();
            DrawRectangle(200, 300, 70, 90, RED); //drawing the quest giver
            //DrawTextureEx(assets.require_texture("player_front.png"),
            //              Vector2{(float)playerX, (float)playerY}, 0, playerSize / 10, WHITE);
        EndDrawing();
    }

    return 0;
}
