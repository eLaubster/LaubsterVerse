#include <iostream>
#include <cmath>
#include "raylib.h"

#include "Planet.h"
#include "Space.h"

#define WIDTH 1280
#define HEIGHT 720

// Simulation speed, in days/second (Must be integer)
#define SIMSPEED 365

using namespace std;


int main(void)
{
    InitWindow(WIDTH, HEIGHT, "LaubsterVerse");
    SetTargetFPS(60);
//    int display = GetCurrentMonitor();
//    SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
//    ToggleFullscreen();

    Space *space = new Space();

    Planet *sun = new Planet(0,0,1.989*pow(10, 30));
    space->addPlanet(*sun);

    Planet *mercury = new Planet(0, 6.982*pow(10, 10), 0.3301*pow(10,24));
    mercury->setVelocity(-38860, 0);
    space->addPlanet(*mercury);

    Planet *venus = new Planet(-1.075*pow(10,11), 0, 4.867*pow(10,24));
    venus->setVelocity(0, -34790);
    space->addPlanet(*venus);

    Planet *earth = new Planet(0, 1.521*pow(10,11),5.972*pow(10, 24));
    earth->setVelocity( -29290, 0);
    space->addPlanet(*earth);

    Planet *mars = new Planet(2.493*pow(10,11), 0, 0.6417*pow(10,24));
    mars->setVelocity(0, 21970);
    space->addPlanet(*mars);

    Planet *jupiter = new Planet(0, 8.163*pow(10,11), 1.898*pow(10,27));
    jupiter->setVelocity(-12440, 0);
    space->addPlanet(*jupiter);

    //space->addPlanet(*new Planet(1.481*pow(10,11)+ 3.844*pow(10,8), 0, 7.348*pow(10,22)));
    //space->planets[2].setVelocity(0, 29780+1022);

    double max = 0;
    double min = 9999999999999999999999.0;

    while(!WindowShouldClose()) {
        int samples = 1000; // Physics samples per frame
        for(int i = 0; i < samples; i++) {
            space->update(GetFrameTime()*(60*60*24*365.25)/8/samples);
        }
        cout << GetFrameTime() << endl;

        BeginDrawing();
//        if(IsMouseButtonDown(0)) {
            //ClearBackground(BLACK);
//        }
        DrawRectangle(2,2,150,500, BLACK);
        DrawFPS(2,2);

        for(Planet p : space->planets) {
            int ox = WIDTH/2;
            int oy = HEIGHT/2;

            float rx = p.x/pow(10,9.5);
            float ry = p.y/pow(10,9.5);

            double dist = space->distance(space->planets[0], space->planets[1]);
            if(dist > max) max = dist;
            if(dist < min) min = dist;

            cout << space->distance(space->planets[0], space->planets[1]) << endl;
            DrawText(to_string(max).c_str(), 2, 50, 14, WHITE);
            DrawText(to_string(min).c_str(), 2, 68, 14, WHITE);
            DrawCircle(ox+rx, oy+ry, .5, WHITE);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}