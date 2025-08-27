#include <iostream>

using namespace std;

class Stack{
    private:
        int* array;
        int top;
        int capacity;

    public:
        Stack(int size){
            this->array = new int[size];
            this->capacity = size;
            this->top = -1;
            cout << "An empty Stack created with the capacity of " << size << endl;
        }

        ~Stack() {
            delete []this->array;
            cout << "Erased" << endl; 
        }

        bool is_full(){
            return this->top == this->capacity - 1;
        }

        bool is_empty(){
            return this->top == -1;
        }

        void push_element(int value){
            if (this->is_full()){
                cout << "Stack is full " << endl;
            }else{
                this->top++;
                this->array[this->top] = value;
            }
        }


};

int main(){
    Stack* mystack = new Stack(10);
    mystack->push_element(1);
    mystack->push_element(2);
    mystack->push_element(3);
    mystack->push_element(4);
}