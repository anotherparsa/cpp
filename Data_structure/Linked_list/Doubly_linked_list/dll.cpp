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

        void print_list(){
            if (this->length == 0){
                cout << "List is empty!" << endl;
            }else{
                cout << "List Elements: " << endl;
                Node* temp_node = this->head;
                while(temp_node != nullptr){
                    cout << temp_node->value << " -> ";
                    temp_node = temp_node->next;
                }
                cout << endl;
            }
        }

};