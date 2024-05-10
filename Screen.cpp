#include "Screen.h"

//Getters
int Screen::getScreenWidth() const{
    return screen_width;
}

int Screen::getScreenHeight() const{
    return screen_height;
}

string Screen::getGameTitle() const{
    return title;
}

Color Screen::getColor(){
    return pink;
}