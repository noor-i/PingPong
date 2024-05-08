#include "Screen.h"

int Screen::getScreenWidth() const{
    return screen_width;
}

int Screen::getScreenHeight() const{
    return screen_height;
}

int Screen::getRectangleWidth() const{
    return rectangle_width;
}

int Screen::getRectangleHeight() const{
    return rectangle_height;
}
string Screen::getGameTitle() const{
    return title;
}