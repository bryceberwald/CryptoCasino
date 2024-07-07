// System Libraries
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// User Libraries
#include "api.hpp"

// External Libraries
#include "../include/raylib/raylib.h"

int main(int argc, char* argv[]) {

    //Get Current Working Directory
    char path_save[1024];
    char cwd[1024];
    char* p;
    if(!(p = strrchr(argv[0], '/'))) {
        getcwd(cwd, sizeof(cwd));
    } else {
        *p = '\0';
        getcwd(path_save, sizeof(path_save));
        chdir(argv[0]);
        getcwd(cwd, sizeof(cwd));
        chdir(path_save);
    }
    string NEW_WORKING_DIR = string(cwd) + "/";
    chdir(NEW_WORKING_DIR.c_str());

   
    // Window Initialization
    InitWindow(1280, 720, "Crypto Casino | v.0.0.1");

    // Initialize curl globally
    CurlGlobalInit();

    // Set Target FPS
    SetTargetFPS(60);

    // Main game loop
    while(!WindowShouldClose()){

        BeginDrawing();
        
        ClearBackground((Color){0, 0, 0, 255 });

        DrawText("Crypto Casino", 530, 250, 32, (Color){ 253, 249, 0, 255 });
        
        EndDrawing();
    };

    // De-Initialization=
    CurlGlobalCleanup();

    CloseWindow();

    // Return '0' to terminate the program.
    return 0;
};