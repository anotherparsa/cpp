#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* bottom;
    
        Node(int value){
            this->value = value;
            this->bottom = nullptr;
        }
};