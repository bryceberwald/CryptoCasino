
#include "Game.hpp"

// Default Constructor
Game::Game() {
    this->version = ("0.0.1\n");
    this->help = "help --options | Coming Soon!\n";

    this->loadingScreen = new LoadingScreen();
    this->mainMenuScreen = new MainMenuScreen();
    this->loginScreen = new LoginScreen();
    this->registerScreen = new RegisterScreen();
    this->creditsScreen = new CreditsScreen();
    this->inGameScreen = new InGameScreen();

    this->currentGameState = new CurrentGameState();
    *currentGameState = LOADING_SCREEN;

    this->loadingCounter = 0;

};

// Destructor Constructor
Game::~Game(){
    // n/a
};


// run() - Runs the game from current state
bool Game::run(CurrentGameState *gameState) {
    switch (*gameState){
        case LOADING_SCREEN:
            if(loadingCounter < 150) {
                loadingCounter++;
            } else {
                *gameState = MAIN_MENU_SCREEN;
            }
            loadingScreen->DrawScreen();
            return true;
            break;
        case MAIN_MENU_SCREEN:
            if (GetMouseX() >= this->mainMenuScreen->getLoginButtonPositionX() && GetMouseX() <= this->mainMenuScreen->getLoginButtonPositionX() + this->mainMenuScreen->getLoginButtonWidth() &&
                GetMouseY() >= this->mainMenuScreen->getLoginButtonPositionY() && GetMouseY() <= this->mainMenuScreen->getLoginButtonPositionY() + this->mainMenuScreen->getLoginButtonHeight())
            {
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    *gameState = LOGIN_SCREEN;
                } else {
                    *gameState = MAIN_MENU_SCREEN;
                }
            }
            else if (GetMouseX() >= this->mainMenuScreen->getRegisterButtonPositionX() && GetMouseX() <= this->mainMenuScreen->getRegisterButtonPositionX() + this->mainMenuScreen->getRegisterButtonWidth() &&
                     GetMouseY() >= this->mainMenuScreen->getRegisterButtonPositionY() && GetMouseY() <= this->mainMenuScreen->getRegisterButtonPositionY() + this->mainMenuScreen->getRegisterButtonHeight())
            {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    *gameState = REGISTER_SCREEN;
                } else {
                    *gameState = MAIN_MENU_SCREEN;
                }
            }
            else if (GetMouseX() >= this->mainMenuScreen->getCreditsButtonPositionX() && GetMouseX() <= this->mainMenuScreen->getCreditsButtonPositionX() + this->mainMenuScreen->getCreditsButtonWidth() &&
                     GetMouseY() >= this->mainMenuScreen->getCreditsButtonPositionY() && GetMouseY() <= this->mainMenuScreen->getCreditsButtonPositionY() + this->mainMenuScreen->getCreditsButtonHeight())
            {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    *gameState = CREDITS_SCREEN;
                }
                else
                {
                    *gameState = MAIN_MENU_SCREEN;
                }
            }
            else if (GetMouseX() >= this->mainMenuScreen->getExitButtonPositionX() && GetMouseX() <= this->mainMenuScreen->getExitButtonPositionX() + this->mainMenuScreen->getExitButtonWidth() &&
                     GetMouseY() >= this->mainMenuScreen->getExitButtonPositionY() && GetMouseY() <= this->mainMenuScreen->getExitButtonPositionY() + this->mainMenuScreen->getExitButtonHeight())
            {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    *gameState = EXIT_SCREEN;
                }
                else
                {
                    *gameState = MAIN_MENU_SCREEN;
                }
            }
            mainMenuScreen->DrawScreen();
            return true;
            break;
        case LOGIN_SCREEN:
            this->loginScreen->DrawScreen();
            return true;
            break;
        case REGISTER_SCREEN:
            this->registerScreen->DrawScreen();
            return true;
            break;
        case CREDITS_SCREEN:
            this->creditsScreen->DrawScreen();
            return true;
            break;
        case GAME_SCREEN:
            this->inGameScreen->DrawScreen();
            return true;
            break;
        case EXIT_SCREEN:
            return false;
            break;
        default:
            std::cout << "ERROR: Invalid Game State" << std::endl;
            break;
    }
}
void Game::printVersion() {
};

/*************************************************
 *             Mutator Functions                 *
 *************************************************/

// setVersion() - Sets the version of the game
void Game::setVersion(string version) {
    this->version = version;
};

// setHelp() - Sets the help string with the help commands
void Game::setHelp(string help) {
    this->help = help;
};

/*************************************************
 *              Accessor Functions               *
 *************************************************/

// getUsersOnline() - Returns the number of users online
string Game::getVersion(){
    return version;
};

// getHelp() - Returns the help string
string Game::getHelp() {
    return help; // TODO: Change this to a array/vector of help commands.
};