#ifndef BALL_H
#define BALL_H
#include <iostream>
#include <raylib.h>

class Ball {
public:
    float x, y;
    int speed_x;
    int speed_y;
    int radius;

    void Draw();
};

#endif // BALL_H