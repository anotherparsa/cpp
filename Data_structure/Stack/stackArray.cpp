#include <iostream>
#include <limits>
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

        void print_stack(){
            if (this->is_empty()){
                cout << "Stack is empty" << endl;
            }else{
                cout << "Stack elements" << endl;
                for (int i = 0 ; i < this->top + 1; i++){
                    cout << this->array[i] << " ";
                }
                cout << endl;
            }
        }

        void push_element(int value){
            if (this->is_full()){
                cout << "Stack is full " << endl;
            }else{
                this->top++;
                this->array[this->top] = value;
            }
        }

        int pop_element(){
            if (this->is_empty()){
                cout << "Stack is empty" << endl;
                return numeric_limits<int>::min();
            }else{
                int popped_value = this->array[top];
                this->top--;
                cout << "Deleted " << popped_value << endl;
                return popped_value;
            }
        }


};

int main(){
    Stack* mystack = new Stack(10);
    cout << mystack->pop_element() << endl;
    cout << "------------------------------------" << endl;
    mystack->push_element(1);
    mystack->push_element(2);
    mystack->push_element(3);
    mystack->push_element(4);
    mystack->print_stack();
    cout << "-----------------------------------" << endl;
    cout << mystack->pop_element() << endl;;
    cout << mystack->pop_element() << endl;
    cout << "-----------------------------------" << endl;
    mystack->print_stack();
}