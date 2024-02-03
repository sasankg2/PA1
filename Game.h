#include <fstream>
#include <iostream>
#include <sstream>
#include <random>
#include "LinkedList.h"
using namespace std;
class Game{
    private:
        int numberPlayer;
        LinkedList linkedlist;
        struct profile{
            string name;
            int points;
        };
        profile players[100];
    public:
        Game();
        int playGame();
        void searchName(string name);
        void insertNewPlayer(profile info);
        int *randomNumberGenerate(int questions, int n);
        int *randomDescription(int index);
        void gameRules(void);
        void newGame();
        void oldGame();
        void addCommand();
        void remove();
        void display();
        void exit();
        void loadCommands();
        void loadPlayers();
};