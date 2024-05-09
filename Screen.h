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

public:
    int getScreenWidth() const;
    int getScreenHeight() const;
    string getGameTitle() const;  
};

#endif //SCREEN_H