#include <string>
using namespace std;
class NODETYPE{
    public:
        NODETYPE();
        NODETYPE(string command, string description, int value);
        NODETYPE *next;
        string command;
        string description;        
        int value;
};