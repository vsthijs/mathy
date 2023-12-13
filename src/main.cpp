#include "assets.hpp"
#include "window.hpp"
#include "raylib.h"
#include <iostream>

// unsigned int playerSize = 50;
// int mouseX, mouseY;

struct Player
{
    float x, y;
    int width, height;
    float speed;

    void Draw()
    {
        DrawRectangle(x, y, width, height, BLUE);
    }
};

struct Wizard
{
    float x, y;
    int width, height;

    Rectangle wizard = {x, y, (float)width, (float)height};

    void Draw()
    {
        DrawRectangleRec(wizard, RED);
    }
};

int main(int argc, char** argv) {
    //setup
    Window win{"mathy", 900, 600};
    AssetManager assets{ASSETS_PATH};
    InitAudioDevice();

    // load
    Sound backgroundmusic = assets.require_sound("background_music.wav");

    // setting player variables
    Player player;
    player.x = 450;
    player.y = 300;
    player.width = 60;
    player.height = 100;
    player.speed = 200.0f;

    // setting Wizard variables
    Wizard wizard;
    wizard.x = 200;
    wizard.y = 300;
    wizard.width = 70;
    wizard.height = 90;

    //SetTargetFPS(60);
    SetExitKey(KEY_Q);

    // game loop
    while (!WindowShouldClose()) {
        // TODO: gebruik dit om te bewegen, net als met Unity's deltaTime.
        float deltatime = GetFrameTime();

        if (IsKeyDown(KEY_W))
        {
            player.y -= player.speed * deltatime; // moving up
        } 
        else if (IsKeyDown(KEY_S))
        {
            player.y += player.speed * deltatime; // moving down
        } 
        else if (IsKeyDown(KEY_A))
        {
            player.x -= player.speed * deltatime; // moving left
        }
        else if (IsKeyDown(KEY_D))
        {
            player.x += player.speed * deltatime; // moving right
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            PlaySound(backgroundmusic);
        }


        BeginDrawing();
            ClearBackground(WHITE);
            DrawFPS(10, 10);
            player.Draw(); // drawing the player
            wizard.Draw(); // drawing the wizard
            // DrawTextureEx(assets.require_texture("player_front.png"),
            //              Vector2{(float)playerX, (float)playerY}, 0, playerSize / 10, WHITE);
        EndDrawing();
    }

    // unload
    UnloadSound(backgroundmusic);

    CloseAudioDevice();
    return 0;
}
