#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <raylib.h>
#include <string>

using namespace std;

class Screen {
private:
    const int screen_width = 1280;
    const int screen_height = 800;
    const string title = "Noor's Pong Game!";
    const int rectangle_width = 25;
    const int rectangle_height = 120;

public:
    int getScreenWidth() const;
    int getScreenHeight() const;
    int getRectangleWidth() const;
    int getRectangleHeight() const;
    string getGameTitle() const;  
};

#endif //SCREEN_H