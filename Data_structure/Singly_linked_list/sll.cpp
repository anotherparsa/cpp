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

        Node* get_node_by_index(int index){
            if (this->length == 0){
                return nullptr;
            }else if (index < 0 || index >= this->length){
                return nullptr;
            }else{
                Node* temp_node = this->head;
                for (int i = 0 ; i < index ; i++){
                    temp_node = temp_node->next;
                }
                return temp_node;
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

        void delete_last_node(){
            if (this->length == 0){
                cout << "The list is empty!" << endl;
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
                previous_node->next = nullptr;
                this->tail = previous_node;
            }
            delete temp_node;
            this->length--;
        }

        void prepend_node(int value){
            Node* new_node = new Node(value);
            if (this->length == 0){
                this->head = new_node;
                this->tail = new_node;
            }else{
                new_node->next = this->head;
                this->head = new_node;
            }
            this->length++;
        }

        void delete_first_node(){
            if (this->length == 0){
                cout << "The list is empty!" << endl;
                return;
            }
            Node* temp_node = this->head;
            if (this->length == 1){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                this->head = this->head->next;
            }
            delete temp_node;
            this->length--;
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
    mysll->delete_last_node();
    mysll->delete_last_node();
    mysll->delete_last_node();
    mysll->delete_last_node();
    mysll->delete_last_node();
    mysll->prepend_node(1);
    mysll->prepend_node(2);
    mysll->prepend_node(3);
    mysll->prepend_node(4);
    mysll->print_list();
    mysll->delete_last_node();
    mysll->delete_last_node();
    mysll->delete_last_node();
    mysll->delete_last_node();
    mysll->delete_last_node();


    
}