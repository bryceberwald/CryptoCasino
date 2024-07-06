#ifndef Game_hpp
#define Game_hpp

//System Libraries
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

// User Libraries
#include "Screen/Screen.hpp"
#include "Screen/LoadingScreen/LoadingScreen.hpp"
#include "Screen/MainMenuScreen/MainMenuScreen.hpp"
#include "Screen/LoginScreen/LoginScreen.hpp"
#include "Screen/RegisterScreen/RegisterScreen.hpp"
#include "Screen/CreditsScreen/CreditsScreen.hpp"
#include "Screen/InGameScreen/InGameScreen.hpp"

// External Libraries
#include <raylib.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

// enum data structure to hold all the game screen value's as an integer value.
enum CurrentGameState{
    LOADING_SCREEN,
    MAIN_MENU_SCREEN,
    LOGIN_SCREEN,
    REGISTER_SCREEN,
    CREDITS_SCREEN,
    GAME_SCREEN,
    EXIT_SCREEN
};

// Game Class Definition
class Game {
    
    public:
        // Default Constructor & default Destructor
        Game();
        ~Game();

        // Class specific methods
        bool run(CurrentGameState *gameState);
        void printVersion();

        // Setters
        void setVersion(string version);
        void setHelp(string help);

        // Getters
        string getVersion();
        string getHelp();

    private:
        string version;
        string help;

        LoadingScreen *loadingScreen;
        MainMenuScreen *mainMenuScreen;
        LoginScreen *loginScreen;
        RegisterScreen *registerScreen;
        CreditsScreen *creditsScreen;
        InGameScreen *inGameScreen;

        CurrentGameState *currentGameState;

        int loadingCounter;
};

#endif /* Game_hpp */