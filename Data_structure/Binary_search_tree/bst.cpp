#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value){
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
};

class BST{
    private:
        Node* root;
    
    public:
        BST(){
            this->root = nullptr;
        }
};