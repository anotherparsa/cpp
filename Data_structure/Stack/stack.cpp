#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* bottom;
    
        Node(int value){
            this->value = value;
            this->bottom = nullptr;
        }
};

class Stack{
    private:
        Node* top;
        int height;
    
    public:
        Stack(){
            this->top = nullptr;
            this->height = 0;
        }

        void print_stack(){
            if (this->height == 0){
                cout << "Stack is empty" << endl;
            }else{
                Node* temp_node = this->top;
                cout << "Stack elements: " << endl;
                while (temp_node != nullptr){
                    cout << temp_node->value << endl << "|" << endl << "۷" << endl;
                    temp_node = temp_node->bottom;
                }
                cout << "Null" << endl;
            }
        }

        void push_node(int value){
            Node* new_node = new Node(value);
            new_node->bottom = this->top;
            this->top = new_node;
            this->height++;
        }

        void pop_node(){
            if (this->height == 0){
                cout << "Stack is empty!" << endl;
                return;
            }else{
                Node* temp_node = this->top;
                this->top = this->top->bottom;
                delete temp_node;
                this->height--;
            }
        }
};

int main(){
    Stack* mystack = new Stack();
    mystack->push_node(1);
    mystack->push_node(2);
    mystack->push_node(3);
    mystack->push_node(4);
    mystack->print_stack();
    mystack->pop_node();
    mystack->pop_node();
    mystack->print_stack();
    mystack->pop_node();
    mystack->pop_node();
    mystack->pop_node();

}