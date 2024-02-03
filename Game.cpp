#include "Game.h"
Game::Game(){
    loadCommands();
    loadPlayers();
}
int Game::playGame(){
    int questions = 0, option = 0, points = 0;
    cout << "Enter the amount of questions you want (5-30):" << endl;
    cin >> questions;
    if(questions < 5 || questions > 30){
        exit();
    }
    else{
        int* arr = randomNumberGenerate(questions, linkedlist.count);
        for(int i=0; i<questions; i++){
            NODETYPE *temp = linkedlist.getNode(arr[i]);
            int * randi = randomDescription(arr[i]);
            NODETYPE *temp1 = linkedlist.getNode(randi[0]);
            NODETYPE *temp2 = linkedlist.getNode(randi[1]);
            cout << "What is the right description for the command " << temp->command << "?" << endl;
            cout << "1. " << temp->description << endl;
            cout << "2. " << temp1->description << endl;
            cout << "3. " << temp2->description << endl;
            cin >> option;
            if(option == 1){
                points++;
            }
        }
    }
    return points;
}
void Game::searchName(string name){
    for(int i=0; i<numberPlayer; i++){
        if(players[i].name.compare(name) == 0){
            int points = playGame();
            players[i].points = points;
            break;
        }
    }
}
void Game::insertNewPlayer(profile info){
    for(int i=numberPlayer-1; i>=0; i--){
        players[i+1] = players[i];
    }
    players[0] = info;
    numberPlayer++;
}
int *Game::randomNumberGenerate(int questions, int n){
    random_device ran;
    mt19937 gen(ran());
    uniform_int_distribution<int> distribution(1, n);
    int* randomNumbers = new int[questions];
    for (int i = 0; i < questions; ++i) {
        randomNumbers[i] = distribution(gen);
    }

    return randomNumbers;
}
int *Game::randomDescription(int index){
    random_device r;
    mt19937 gen(r());
    uniform_int_distribution<int> distribution(1, index);
    int* randomNumbers = new int[2];
    randomNumbers[0] = distribution(gen);
    do {
        randomNumbers[1] = distribution(gen);
    } while (randomNumbers[1] == randomNumbers[0]);
    return randomNumbers;
}
void Game::gameRules(void){
    cout << "This game is a matching game where you match certain commands with the right description. You will be asked to pick an amount of commands to match (5-30) and will be given those amount of commands at random. Each command will get three different descriptions and only one of them will be right. Based of wether you get them right or wrong you will either gain points or lose points. You can save your progress and continue to play from it or start over with a new profile." << endl;
}
void Game::newGame(){
    string name;
    cout << "Enter your name:" << endl;
    cin >> name;
    profile info;
    info.name = name;
    int points = playGame();
    info.points = points;
    insertNewPlayer(info);
    
}
void Game::oldGame(){
    string name;
    cout << "Choose an existing profile to play the game:" << endl;
    cin >> name;
    searchName(name);
}
void Game::addCommand(){
    string command, description;
    int value=0;
    cout << "Enter a new Command:" << endl;
    cin >> command;
    cout << "Enter a Description for the Command:" << endl;
    cin >> description;
    cout << "Enter a Value for the Command:" << endl;
    cin >> value;
    linkedlist.insertNode(command, description, value);
}
void Game::remove(){
    string command;
    cout << "Enter a command to get removed:" << endl;
    cin >> command;
    linkedlist.removeNode(command);
}
void Game::display(){
    NODETYPE *temp = linkedlist.headNode;
    while(temp != NULL){
        cout << temp->command << "," << temp->description << "," << temp->value << endl;
        temp = temp->next;
    }
}
void Game::exit(){
    NODETYPE *startNode = linkedlist.headNode;
    const std::string fileName = "commands.csv";
    ofstream outputFile(fileName);
    string fileName1 = "profiles.csv";
    ofstream outputFile1(fileName1);
    if (!outputFile.is_open()) {
        cerr << "Error opening the file: " << fileName << endl;
        return; // Return an error code
    }
    while(startNode != NULL){
        outputFile << startNode->command << "," << "\"" << startNode->description << "\"" << "," << startNode->value << endl;
        startNode = startNode->next;
    }
    if (!outputFile1.is_open()) {
        cerr << "Error opening the file: " << fileName1 << endl;
        return; // Return an error code
    }
    for(int i=0; i<numberPlayer; i++){
        outputFile1 << players[i].name << ", " << players[i].points << endl;
    }

    outputFile.close();
    outputFile1.close();
}
void Game::loadCommands(){
    const std::string fileName = "commands.csv";
    ifstream inputFile(fileName);
    string line;
    while (getline(inputFile, line)) {
        istringstream isStream(line);

        // Initialize variables to store parsed values
        std::string command;
        std::string description;
        int points = 0;

        // Parse the line
        getline(isStream, command, ','); // Read until the first comma into command
        getline(isStream, description, ','); // Read until the second comma into description
        isStream >> points;
        linkedlist.insertNode(command, description, points);

    }
}
void Game::loadPlayers(){
    const std::string fileName = "profiles.csv";
    ifstream inputFile(fileName);
    string line;
    profile info;
    while (getline(inputFile, line)) {
        istringstream isStream(line);

        // Initialize variables to store parsed values
        std::string name;
        int points = 0;

        // Parse the line
        getline(isStream, name, ','); // Read until the first comma into command
        isStream >> points;
        info.name = name;
        info.points = points;
        insertNewPlayer(info);
    }
}