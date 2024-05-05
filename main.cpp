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
    //By defining frames per second, we make sure the game runs on the
    //same speed on every computer
    SetTargetFPS(60);

    //WindowShouldClose() checks if the escape key on keyboard in pressed
    //or if the close button on the window is pressed.
    while(WindowShouldClose()==false){
        BeginDrawing();

        EndDrawing();
    }

    CloseWindow();
    return 0;    
}

