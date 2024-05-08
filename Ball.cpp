#include "Ball.h"

void Ball::Draw(){
    DrawCircle(x, y, 20, PINK); 
}

void Ball::Update(){
    x += speed_x;
    y += speed_y;
}