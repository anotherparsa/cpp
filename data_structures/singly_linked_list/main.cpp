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

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        LinkedList(){
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }

        void append_node(int value){
            Node* new_node = new Node(value);
            if (this->length == 0){
                this->head = new_node;
                this->tail = new_node;
            }else{
                this->tail->next = new_node;
                this->tail = new_node;
            }
            this->length++;
        }

        void delete_last_node(){
            if (this->length == 0){
                return;
            }
            Node* temp_node = this->head;
            if (this->length == 1){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
            Node* previous_node = this->head;
            while (temp_node->next != nullptr){
                previous_node = temp_node;
                temp_node = temp_node->next;
            }
            this->tail = previous_node;
            this->tail->next = nullptr;
            }
            this->length--;
            delete temp_node;
        }
};

