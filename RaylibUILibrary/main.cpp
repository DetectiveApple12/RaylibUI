#include "raylib.h"
#include "InputBar.hpp"
#include "Button.hpp"

int main(void)
{
    const int screenWidth = 1600;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Showcase");

    InputBar name (500, 200, 400, 50, { 255, 255, 255, 255 }, { 0, 0, 0, 255 }, 20, "Username...", {200, 200, 200, 255}, 1, 5);
    Button button (500, 400, "Click", [](void* x) {std::cout << ((InputBar*)x)->GetText() << std::endl;}, (void*)&name);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        name.Input();
        button.Input();

        BeginDrawing();

            ClearBackground(RED);

            name.Draw();
            button.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}