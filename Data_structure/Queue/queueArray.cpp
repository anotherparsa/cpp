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
};