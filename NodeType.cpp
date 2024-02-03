#include "NodeType.h"
NODETYPE::NODETYPE(){
    command = "";
    description = "";
    value = 0;
    next = NULL;
}
NODETYPE::NODETYPE(string command, string description, int value){
    //this-> refers to member variables
    this->command = command;
    this->description = description;
    this->value = value;
    next = NULL;
}