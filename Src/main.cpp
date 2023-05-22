#include "GameManager.h"
#include <Windows.h>
#include "Debugger/Debug.h"

GameManager* gameManager = new GameManager();  // Create a new GameManager object.

int main()
{
#ifdef NDEBUG
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);  // Hide the console window if the program is compiled in release mode.
#endif

    gameManager->StartGameManager();  // Start the game manager.

    gameManager->Update();  // Update the game.

    delete gameManager;  // Delete the game manager object to free up memory.

    // The program ends here.
}
