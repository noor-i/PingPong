#include <iostream>
#include <raylib.h>
#include <cstring>
#include "Ball.h"
#include "Screen.h"
#include "Paddle.h"
#include "PaddleCPU.h"

using namespace std;

int main() {
    Ball b;
    Paddle player;
    PaddleCPU cpu;

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
        cpu.Update(b.y_pos);

        //Drawing
        ClearBackground(BLACK);
        DrawLine(screen_width/2, 0, screen_width/2, screen_width, GRAY);
        b.Draw();
        cpu.Draw();
        player.Draw();
        //End Drawing

        EndDrawing();
    }

    CloseWindow();
    return 0;    
}

