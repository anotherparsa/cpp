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
                cout << "List Elements: " << endl << "null <-> ";
                Node* temp_node = this->head;
                while(temp_node != nullptr){
                    cout << temp_node->value << " <-> ";
                    temp_node = temp_node->next;
                }
                cout << "null" << endl;
            }
        }

        Node* get_node_by_index(int index){
            if (this->length == 0){
                cout << "List is empty" << endl;
                return nullptr;
            }else if (index < 0 || index >= this->length){
                cout << "Invalid Index" << endl;
                return nullptr;
            }else{
                Node* temp_node = this->head;
                if (index < this->length / 2){
                    for (int i = 0 ; i < index ; i++){
                        temp_node = temp_node->next;
                    }
                }else{
                    temp_node = this->tail;
                    for (int i = this->length - 1 ; i > index ; i--){
                        temp_node = temp_node->previous;
                    }
                }
                if (temp_node != nullptr){
                    return temp_node;
                }
                return temp_node;
            }
        }

        void set_node_value(int index, int value){
            if (this->length == 0){
                cout << "List is empty!" << endl;
                return;
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
                new_node->previous = this->tail;
                this->tail = new_node;
            }
            this->length++;
        }

        void delete_last_node(){
            if (this->length == 0){
                cout << "List is empty!" << endl;
                return;
            }
            Node* temp_node = this->tail;
            if (this->length == 1){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                this->tail = this->tail->previous;
                this->tail->next = nullptr;
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
                this->head->previous = new_node;
                this->head = new_node;
            }
            this->length++;
        }

        void delete_first_node(){
            if (this->length == 0){
                cout << "List is empty" << endl;
                return;
            }
            Node* temp_node = this->head;
            if (this->length == 1){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                this->head = this->head->next;
                this->head->previous = nullptr;
            }
            delete temp_node;
            this->length--;
        }

        void inset_node(int index, int value){
            if (index < 0 || index > this->length){
                cout << "Invalid Index" << endl;
                return;
            }else if (index == 0){
                this->prepend_node(value);
                return;
            }else if (index == this->length){
                this->append_node(value);
                return;
            }else{
                Node* new_node = new Node(value);
                Node* before_node = this->get_node_by_index(index - 1);
                Node* after_node = before_node->next;
                before_node->next = new_node;
                new_node->previous = before_node;
                after_node->previous = new_node;
                new_node->next = after_node;
                this->length++;
            }
        }

        void delete_node(int index){
            if (this->length == 0 ){
                cout << "List is empty" << endl;
                return;
            }else if (index < 0 || index >= this->length){
                cout << "Invalid Index" << endl;
                return;
            }else if (index == 0){
                this->delete_first_node();
                return;
            }else if (index == this->length - 1){
                this->delete_last_node();
                return;
            }else{
                Node* temp_node = this->get_node_by_index(index);
                Node* after_node = temp_node->next;
                Node* before_node = temp_node->previous;
                before_node->next = after_node;
                after_node->previous = before_node;
                delete temp_node;
                this->length--;
            }
        }
};

int main(){


}