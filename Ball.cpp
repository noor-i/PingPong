#include "Ball.h"

// Ball constructor
Ball::Ball(){
    x_pos = s.getScreenWidth()/2;
    y_pos = s.getScreenHeight()/2;
    speed_x = 7;
    speed_y = 7;
    radius = 20;
}

// Draws ball
void Ball::Draw(){
    DrawCircle(x_pos, y_pos, 20, Color{169,255,188,255}); 
}

// Checks if the ball is within screen bounds and does collision check and score 
// update, if the ball reaches user/cpu opponent's wall == a win.
void Ball::Update(){
    x_pos += speed_x;
    y_pos += speed_y;

    if((y_pos + radius) >= s.getScreenHeight() || (y_pos - radius) <= 0)
    {
        speed_y *= -1;
    }
    if((x_pos + radius) >= s.getScreenWidth()) //CPU wins
    {
        cpu_score++;
        ResetBall();
    }
    if((x_pos - radius) <= 0) //CPU wins
    {
        player_score++;
        ResetBall();
    }
}

//Sets ball back in the middle of the gameboard every time it scores and
//or goes out of screen bounds. It randomizes the ball's movement as well.
void Ball::ResetBall(){
    x_pos = s.getScreenWidth()/2;
    y_pos = s.getScreenHeight()/2;

    //possible directions the ball can move from (right/left/up/down)
    int speed_choices[2] = {-1,1}; 
    speed_x *= speed_choices[GetRandomValue(0,1)];
    speed_y *= speed_choices[GetRandomValue(0,1)];
}

//Getter
Screen Ball::getScreen() const {
    return s;
}