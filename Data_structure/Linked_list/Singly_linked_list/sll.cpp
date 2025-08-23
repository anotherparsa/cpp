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

        void set_node_value(int index, int value){
            if (this->length == 0){
                cout << "List is empty!" << endl;
                return;
            }else if (index < 0 || index >= this->length){
                cout << "Invalid index!" << endl;
            }else{
                Node* temp_node = this->get_node_by_index(index);
                if (temp_node != nullptr){
                    temp_node->value = value;
                }
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

        void insert_node(int index, int value){
            if (index < 0 || index > this->length){
                cout << "Invalid index!" << endl;
                return;
            }else if (index == 0){
                this->prepend_node(value);
                return;
            }else if (index == this->length){
                this->append_node(value);
                return;
            }else{
                Node* new_node = new Node(value);
                Node* previous_node = this->get_node_by_index(index - 1);
                if (previous_node != nullptr){
                    new_node->next = previous_node->next;
                    previous_node->next = new_node;
                    this->length++;
                }
            }
        }

        void delete_node(int index){
            if (this->length == 0){
                cout << "List is empty!" << endl;
                return;
            }else if (index < 0 || index >= this->length){
                cout << "Invalid Index!" << endl;
                return;
            }else if (index == 0){
                this->delete_first_node();
                return;
            }else if (index == this->length - 1){
                this->delete_last_node();
                return;
            }else{
                Node* previous_node = this->get_node_by_index(index - 1);
                if (previous_node != nullptr){
                    Node* temp_node = previous_node->next;
                    previous_node->next = temp_node->next;
                    delete temp_node;
                    this->length--;
                }
            }
        }

        void reverse_list(){
            if (this->length == 0){
                cout << "list is empty" << endl;
            }else{
                Node* temp_node = this->head;
                Node* after_node = this->head;
                Node* before_node = nullptr;
                this->head = this->tail;
                this->tail = temp_node;
                for (int i = 0 ; i < this->length ; i++){
                    after_node = temp_node->next;
                    temp_node->next = before_node;
                    before_node = temp_node;
                    temp_node = after_node;
                }
            }
        }

};

int main(){

}