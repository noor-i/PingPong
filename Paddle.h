#ifndef PADDLE_H
#define PADDLE_H
#include <iostream>
#include <raylib.h>
#include "Ball.h"

class Paddle{
public:
    float x,y;
    float width, height;
    int speed;

    Paddle();
    void Draw();
    void Update();

private:
    Screen s;
};


#endif // PADDLE_H