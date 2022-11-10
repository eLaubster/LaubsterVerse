#include <iostream>
#include "raylib.h"

#define WIDTH 1280
#define HEIGHT 720

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "LaubsterVerse");
    SetTargetFPS(60);
//    int display = GetCurrentMonitor();
//    SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
//    ToggleFullscreen();

    float r = 20;
    float bx = r;
    float by = r;
    float velx = 5;
    float vely = 5;

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle(bx, by, 20, BLUE);
        DrawRectangle(GetMouseX()-5, GetMouseY()-5, 10, 10, GREEN);
        bx += velx;
        by += vely;

        if(bx > WIDTH-r || bx < r) velx *= -1;
        if(by > HEIGHT-r || by < r) vely *= -1;

        EndDrawing();
    }

    CloseWindow();

    return 0;
}