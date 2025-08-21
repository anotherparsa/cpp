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

class SLL{
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        SLL(){
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }

        void print_list(){
            if (this->length == 0){
                cout << "List is empty: " << endl;
            }else{
                Node* temp_node = this->head;
                cout << "List Items: " << endl;
                while (temp_node != nullptr){
                    cout << temp_node->value << " ";
                    temp_node = temp_node->next;
                }
                cout << endl;
            }
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
};

int main(){
    SLL* mysll = new SLL();
    mysll->print_list();
    mysll->append_node(1);
    mysll->append_node(2);
    mysll->append_node(3);
    mysll->append_node(4);
    mysll->print_list();
}