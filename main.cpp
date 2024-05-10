#include <iostream>
#include <raylib.h>
#include <cstring>
#include "Ball.h"
#include "Screen.h"
#include "Paddle.h"
#include "PaddleCPU.h"
//Source used to get game user interface colours:
//https://www.w3schools.com/html/html_colors_rgb.asp#:~:text=RGB%20Color%20Values&text=Each%20parameter%20(red%2C%20green%2C,x%20256%20%3D%2016777216%20possible%20colors!

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
        ClearBackground(b.getScreen().getColor());
        //User background to the right of the divider (light pink)
        DrawRectangle(screen_width/2, 0, screen_width/2, screen_height, {255, 226,229, 100});
        //Circle accent on gameboard (light transparent green)
        DrawCircle(screen_width/2, screen_height/2, 145, Color{226,255,226,50});
        //Gameboard divider (pong fence)
        DrawLine(screen_width/2, 0, screen_width/2, screen_width, GRAY);

        b.Draw();
        cpu.Draw();
        player.Draw();

        DrawText(TextFormat("%i", b.cpu_score), screen_width/4, 20, 80, WHITE);
        DrawText(TextFormat("%i", b.player_score), (screen_width/4) * 3, 20, 80, WHITE);
        //End Drawing

        EndDrawing();
    }

    CloseWindow();
    return 0;    
}

