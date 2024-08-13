#include "raylib.h"
#include "InputBar.hpp"

int main(void)
{
    const int screenWidth = 1600;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Showcase");

    InputBar name (500, 200, 400, 50, { 255, 255, 255, 255 }, { 0, 0, 0, 255 }, 20, "Username...", {200, 200, 200, 255}, 1, 5);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        name.Input();

        BeginDrawing();

            ClearBackground(RED);

            name.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}