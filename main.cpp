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

        //Check for collisions
        if(CheckCollisionCircleRec(Vector2{b.x_pos,b.y_pos}, 
                                    b.radius,
                                    Rectangle{player.x, player.y, player.width, player.height}))
        {
            b.speed_x *= -1;
        }
        if(CheckCollisionCircleRec(Vector2{b.x_pos,b.y_pos}, 
                                    b.radius,
                                    Rectangle{cpu.x, cpu.y, cpu.width, cpu.height}))
        {
            b.speed_x *= -1;
        }

        //Drawing
        ClearBackground(BLACK);
        DrawLine(screen_width/2, 0, screen_width/2, screen_width, GRAY);
        b.Draw();
        cpu.Draw();
        player.Draw();
        DrawText(TextFormat("%i", b.cpu_score), screen_width/4, 20, 80, DARKPURPLE);
        DrawText(TextFormat("%i", b.player_score), (screen_width/4) * 3, 20, 80, DARKPURPLE);
        //DrawText(text, x, y, 80, DARKPURPLE);
        //End Drawing

        EndDrawing();
    }

    CloseWindow();
    return 0;    
}

