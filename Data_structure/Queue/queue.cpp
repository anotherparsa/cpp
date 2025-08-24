#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* before;

        Node(int value){
            this->value = value;
            this->before = nullptr;
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
                    temp_node = temp_node->before;
                }
                cout << "Null" << endl;
            }
        }

        void enqueue_node(int value){
            Node* new_node = new Node(value);
            if (this->length == 0){
                this->first = new_node;
                this->last = new_node;
            }else {
                this->last->before = new_node;
                this->last = new_node;
            }
            this->length++;
        }

        void dequeue_node(){
            if (this->length == 0){
                cout << "The queue is empty" << endl;
                return;
            }
            Node* temp_node = this->first;
            if (this->length == 1){
                this->first = nullptr;
                this->last = nullptr;
            }else{
                this->first = this->first->before;
            }
            delete temp_node;
            this->length--;
        }
};

int main(){
    
}