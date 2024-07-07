#include "main.hpp"

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
    InitWindow(1280, 720, "Savages-Online | Version 0.0.1");

    // Initialize curl globally
    CurlGlobalInit();

    // Predetermined variable value's during the pre-game state.
    bool isGameRunning = true;

    // Set Target FPS
    SetTargetFPS(60);

    // Main game loop
    while(!WindowShouldClose() && isGameRunning){

        BeginDrawing();

        
        EndDrawing();
    };

    // De-Initialization=
    CurlGlobalCleanup();
    CloseWindow();

    // Return '0' to terminate the program.
    return 0;
};