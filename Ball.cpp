#include "Ball.h"

Ball::Ball(){
    x_pos = s.getScreenWidth()/2;
    y_pos = s.getScreenHeight()/2;
    speed_x = 7;
    speed_y = 7;
    radius = 20;
}

void Ball::Draw(){
    DrawCircle(x_pos, y_pos, 20, WHITE); 
}

void Ball::Update(){
    x_pos += speed_x;
    y_pos += speed_y;

    if((y_pos + radius) >= s.getScreenHeight() || (y_pos - radius) <= 0)
    {
        speed_y *= -1;
    }
    if((x_pos + radius) >= s.getScreenWidth() || (x_pos - radius) <= 0)
    {
        speed_x *= -1;
    }
}

Screen Ball::getScreen() const {
    return s;
}