#include "Paddle.h"
#include "Screen.h"

Paddle::Paddle(){
    width = 25;
    height = 120;
    x = s.getScreenWidth() - width - 10;
    y = s.getScreenHeight()/2 - height/2; 
    speed = 6;
}

void Paddle::Draw(){
    DrawRectangle(x, y, width, height, PINK);    
}

void Paddle::Update(){
    if(IsKeyDown(KEY_UP)){
        y = y - speed;
    }
    if(IsKeyDown(KEY_DOWN)){
        y = y + speed;
    }
    LimitMovement();
}

void Paddle::LimitMovement(){
    if(y <= 0){
        y = 0;
    }
    if(y + height >= s.getScreenHeight()){
        y = s.getScreenHeight() - height;
    }
}