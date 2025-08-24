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

class Stack{
    private:
        Node* top;
        int height;
    
    public:
        Stack(){
            this->top = nullptr;
            this->height = 0;
        }

        void push_node(int value){
            Node* new_node = new Node(value);
            new_node->bottom = this->top;
            this->top = new_node;
            this->height++;
        }
        
};