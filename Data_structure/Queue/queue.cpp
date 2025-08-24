#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* next;

        Node(int value){
            this->value = value;
            this->next = nullptr;
        }
};

class Queue{
    private:
        Node* first;
        Node* last;
        int length;

    public:
        Queue(){
            this->first = nullptr;
            this->last = nullptr;
            this->length = 0;
        }

        void print_queue(){
            if (this->length == 0){
                cout << "Queue is empty" << endl;
                return;
            }else{
                Node* temp_node = this->first;
                cout << "Queue elements: " << endl;
                while (temp_node != nullptr){
                    cout << temp_node->value << " -> "; 
                    temp_node = temp_node->next;
                }
                cout << endl << "Null"
            }
        }
};