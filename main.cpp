#include <iostream>
#include <raylib.h>
#include <cstring>
#include "Ball.h"
#include "Screen.h"
#include "Paddle.h"

using namespace std;

int main() {
    Ball b;
    Paddle player;

    const int screen_width = b.getScreen().getScreenWidth();
    const int screen_height = b.getScreen().getScreenHeight();
    const int y_center = (screen_height/2) - (player.height/2);
    
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
        player.Update();

        //Drawing
        ClearBackground(BLACK);
        DrawLine(screen_width/2, 0, screen_width/2, screen_width, GRAY);
        b.Draw();
        DrawRectangle(10, screen_height/2 - 60, player.width, player.height, PINK);
        player.Draw();
        //End Drawing

        EndDrawing();
    }

    CloseWindow();
    return 0;    
}

