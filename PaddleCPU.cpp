#include "PaddleCPU.h"

PaddleCPU::PaddleCPU(){
    width = 25;
    height = 120;
    x = 10;
    y = s.getScreenHeight()/2 - 60; 
    speed = 6;
}

// AI Algorithm: if the centre of the ball is greater than the 
// centre of the paddle, raise the paddle/racket up 
void PaddleCPU::Update(int ball_y)
{
    //y pos of ball -its centre, is above the y pos of the paddle's centre
    if(y + height/2 > ball_y)
    {
        y = y - speed;
    }
    //y pos of ball, is below y pos of paddle
    if(y + height/2 <= ball_y)
    {
        y = y + speed;
    }
}
