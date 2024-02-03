#include "LinkedList.h"
LinkedList::LinkedList(){
    nodes = NULL;
    count = 0;
    headNode = NULL;
}
void LinkedList::insertNode(string command, string description, int value){
    if(headNode == NULL){
        nodes = new NODETYPE(command, description, value);
        headNode = nodes;
    }
    else{
        nodes = new NODETYPE(command, description, value);
        nodes->next = headNode;
        headNode = nodes;
    }
    count++;
}
void LinkedList::removeNode(string command){
    NODETYPE *startNode = headNode;
    NODETYPE *prev = NULL;
    if(headNode == NULL){
        cout << "Nothing can be removed" << endl;
    }
    else{
        while(startNode != NULL){
            if(startNode->command.compare(command) == 0){
                if(prev == NULL){
                    delete startNode;
                    headNode = NULL;
                    count--;
                    return;
                }
                else{
                    prev->next = startNode->next;
                    delete startNode;
                    count--;
                    return;
                }
            }
            prev = startNode;
            startNode = startNode->next;
        }
        cout << "Could not find a matching command" << endl;
    }

}
NODETYPE *LinkedList::getNode(int index){
    NODETYPE *startNode = headNode;
    int counter = 1;
    while(startNode != NULL){
        if(counter == index){
            return startNode;
        }
        else{
            startNode = startNode->next;
            counter++;
        }
    }
    return NULL;
}