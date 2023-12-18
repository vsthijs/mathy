#include "assets.hpp"
#include "window.hpp"
#include "raylib.h"
#include <iostream>

// unsigned int playerSize = 50;
// int mouseX, mouseY;

// before raylib setup
float screenWidth = 900;
float screenHeight = 600;
Window win{"mathy", 900, 600};
AssetManager assets{ASSETS_PATH};

struct Player
{
    int x, y;
    int width, height;
    int speed;
    Color color;

    void Draw()
    {
        DrawRectangle(x, y, width, height, color);
    }
};

struct Start_button
{
    Texture texture = assets.require_texture("start_button.png");
    int x, y;
    int scale;
    Rectangle hitbox = {450, 300, (float)texture.width * 10, (float)texture.height * 10};

    void Draw()
    {
        DrawTextureEx(assets.require_texture("start_button.png"),
                      Vector2{(float)x, (float)y}, 0, (float)scale, WHITE);
    }

    Player player;
    void Clicked()
    {
        std::cout << "button is clicked";
    }
};

int main(int argc, char** argv) {
    //with raylib setup
    InitAudioDevice();

    // load
    Sound backgroundmusic = assets.require_sound("background_music.wav");

    // setting player variables
    Player player;
    player.x = 450;
    player.y = 300;
    player.width = 60;
    player.height = 100;
    player.speed = 200;
    player.color = BLUE;

    // setting Start button variables
    Start_button start_button;
    start_button.scale = 10;
    start_button.x = 450 - ((start_button.scale * 32) / 2);
    start_button.y = 300 - ((start_button.scale * 32) / 2);

    Vector2 mousePosition;


    //SetTargetFPS(60);
    SetExitKey(KEY_Q);

    // game loop
    while (!WindowShouldClose()) {
        // TODO: gebruik dit om te bewegen, net als met Unity's deltaTime.
        float deltatime = GetFrameTime();

        //get de cordinates of the mouse so you can use it for buttonm clicks
        mousePosition = GetMousePosition();

        if (IsKeyDown(KEY_W))
        {
            player.y -= (float) player.speed * deltatime; // moving up
        } 
        else if (IsKeyDown(KEY_S))
        {
            player.y += (float) player.speed * deltatime; // moving down
        } 
        else if (IsKeyDown(KEY_A))
        {
            player.x -= (float) player.speed * deltatime; // moving left
        }
        else if (IsKeyDown(KEY_D))
        {
            player.x += (float) player.speed * deltatime; // moving right
        }

        // looping background music
        if (!IsSoundPlaying(backgroundmusic) && IsWindowReady())
        {
            PlaySound(backgroundmusic);
        }

        //clicking start_button reaction
        if (CheckCollisionPointRec(mousePosition, start_button.hitbox))
        {
            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            {
                start_button.Clicked();
            }
        }

        BeginDrawing();
            ClearBackground(WHITE);
            DrawFPS(10, 10);
            DrawRectangleRec(start_button.hitbox, RED);
            start_button.Draw();
            //player.Draw(); // drawing the player
            //wizard.Draw(); // drawing the wizard
            // DrawTextureEx(assets.require_texture("player_front.png"),
            //              Vector2{(float)playerX, (float)playerY}, 0, playerSize / 10, WHITE);
        EndDrawing();
    }

    // unload
    UnloadSound(backgroundmusic);

    CloseAudioDevice();
    return 0;
}
