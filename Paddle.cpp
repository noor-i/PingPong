#include "Paddle.h"
#include "Screen.h"

//Paddle constructor
Paddle::Paddle(){
    width = 25;
    height = 120;
    x = s.getScreenWidth() - width - 10;
    y = s.getScreenHeight()/2 - height/2; 
    speed = 6;
}

//Draws a paddle with rounded edges (inheritance: both user and cpu paddle)
void Paddle::Draw(){
    DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);    
}

//Controls user paddle via keys (up/down)
void Paddle::Update(){
    if(IsKeyDown(KEY_UP)){
        y = y - speed;
    }
    if(IsKeyDown(KEY_DOWN)){
        y = y + speed;
    }
    LimitMovement();
}

//Stops the paddles from exiting the screen frame
void Paddle::LimitMovement(){
    if(y <= 0){
        y = 0;
    }
    if(y + height >= s.getScreenHeight()){
        y = s.getScreenHeight() - height;
    }
}