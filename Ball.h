#ifndef BALL_H
#define BALL_H
#include <iostream>
#include <raylib.h>
#include "Screen.h"

class Ball {
public:
    float x_pos;
    float y_pos;
    int speed_x;
    int speed_y;
    int radius;

    int player_score = 0;
    int cpu_score = 0;

    Ball();
    void Draw();
    void Update();
    Screen getScreen() const;
private:
    Screen s;
};

#endif // BALL_H