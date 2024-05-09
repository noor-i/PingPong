#ifndef PADDLECPU_H
#define PADDLECPU_H
#include "Paddle.h"
#include <iostream>
#include <raylib.h>

class PaddleCPU: public Paddle{
public:
    PaddleCPU(); // Constructor
    void Update();
private:
    Screen s;
};

#endif // PADDLECPU_H