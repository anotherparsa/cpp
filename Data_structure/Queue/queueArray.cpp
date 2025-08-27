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


};