#include <iostream>
#include "NodeType.h" 
class LinkedList{
    public:
        LinkedList();
        void insertNode(string command, string description, int value);
        void removeNode(string command);
        NODETYPE *getNode(int index);
        NODETYPE *headNode;
        int count;
    private:
        NODETYPE *nodes;
};