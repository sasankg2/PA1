#include <iostream>
#include "Game.h"
using namespace std;
int main() {
    int option =0;
    Game game;
    while(option != 7){
        cout << "Choose an option below" << endl << "1. Game Rules" << endl << "2. Play New Game" << endl << "3. Load Previous Game" << endl << "4. Add Command" << endl << "5. Remove Command" << endl << "6. Display All Commands" << endl << "7. Save and Exit" << endl;
        cin >> option;
        switch (option) {
        case 1:
            game.gameRules();
            break;
        case 2:
            game.newGame();
            break;
        case 3:
            game.oldGame();
            break;
        case 4:
            game.addCommand();
            break;
        case 5:
            game.remove();
            break;
        case 6:
            game.display();
            break;
        case 7:
            game.exit();
            break;
    }
    }
}
