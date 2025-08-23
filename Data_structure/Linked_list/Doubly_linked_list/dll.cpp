#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node* previous;

        Node(int value){
            this->value = value;
            this->next = nullptr;
            this->previous = nullptr;
        }
};

class DLL{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        DLL(){
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }
};