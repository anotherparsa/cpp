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

};

int main(){
    DLL* mydll = new DLL();
    mydll->prepend_node(1);
    mydll->prepend_node(2);
    mydll->prepend_node(3);
    mydll->prepend_node(4);
    mydll->print_list();
    mydll->delete_first_node();
    mydll->delete_first_node();
    mydll->delete_first_node();
    mydll->delete_first_node();
    mydll->delete_first_node();
    mydll->print_list();
}