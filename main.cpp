#include <iostream>
#include <raylib.h>
#include <cstring>
#include "Ball.h"

using namespace std;

int main() {
    cout << "Starting the game: " << endl;
    const int screen_width = 1280;
    const int screen_height = 800;
    const string title = "Noor's Pong Game!";
    const int rectangle_width = 25;
    const int rectangle_height = 120;
    const int y_center = (screen_height/2) - (rectangle_height/2);

    Ball ball;
    ball.radius = 20;
    ball.x = screen_width/2;
    ball.y = screen_height/2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    InitWindow(screen_width, screen_height, title.c_str());
    //By defining frames per second, we make sure the game runs on the
    //same speed on every computer
    SetTargetFPS(60);

    //WindowShouldClose() checks if the escape key/close button pressed
    while(WindowShouldClose()==false){
        BeginDrawing();
        //Drawing
        DrawLine(screen_width/2, 0, screen_width/2, screen_width, GRAY);
        ball.Draw();
        DrawRectangle(10, y_center, rectangle_width, rectangle_height, MAGENTA);
        DrawRectangle(1245, y_center, rectangle_width, rectangle_height, MAGENTA);
        //End Drawing
        EndDrawing();
    }

    CloseWindow();
    return 0;    
}

