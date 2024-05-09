#include <iostream>
#include <raylib.h>
#include <cstring>
#include "Ball.h"
#include "Screen.h"

using namespace std;

int main() {
    Ball b;

    const int screen_width = b.getScreen().getScreenWidth();
    const int screen_height = b.getScreen().getScreenHeight();
    const int racket_width = b.getScreen().getRectangleWidth();
    const int racket_height = b.getScreen().getRectangleHeight();
    const int y_center = (screen_height/2) - (racket_height/2);
    
    cout << "Starting the game: " << endl;
    InitWindow(screen_width, screen_height, b.getScreen().getGameTitle().c_str());
    //By defining frames per second, we make sure the game runs on the
    //same speed on every computer
    SetTargetFPS(60);

    //WindowShouldClose() checks if the escape key/close button is pressed
    while(WindowShouldClose()==false){
        BeginDrawing();

        //Updating
        b.Update();

        //Drawing
        ClearBackground(BLACK);
        DrawLine(screen_width/2, 0, screen_width/2, screen_width, GRAY);
        b.Draw();
        DrawRectangle(10, y_center, racket_width, racket_height, PINK);
        DrawRectangle(screen_width - 35, y_center, racket_width, racket_height, PINK);
        //End Drawing

        EndDrawing();
    }

    CloseWindow();
    return 0;    
}

