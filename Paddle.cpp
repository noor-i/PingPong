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