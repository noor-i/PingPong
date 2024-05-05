#include <iostream>
#include <raylib.h>
#include <cstring>

using namespace std;

int main() {
    cout << "Starting the game: " << endl;
    const int screen_width = 1280;
    const int screen_height = 800;
    const string title = "Noor's Pong Game!";
    InitWindow(screen_width, screen_height, title.c_str());

    CloseWindow();
    return 0;    
}

