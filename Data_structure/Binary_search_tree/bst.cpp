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
    public:
        Node* root;
        BST(){
            this->root = nullptr;
        }

        void insert_node(int value){
            Node* new_node = new Node(value);
            if (this->root == nullptr){
                this->root = new_node;
                return;
            }else{
                Node* temp_node = this->root;
                while (true){
                    if (new_node->value == temp_node->value){
                        cout << "Can't have duplicate nodes" << endl;
                        return;
                    }else{
                        if (new_node->value < temp_node->value){
                            if (temp_node->left == nullptr){
                                temp_node->left = new_node;
                                return;
                            }else{
                                temp_node = temp_node->left;
                            }
                        }else{
                            if (temp_node->right == nullptr){
                                temp_node->right = new_node;
                                return;
                            }else{
                                temp_node = temp_node->right;
                            }
                        }
                    }
                }
            }
        }
};

int main(){
    BST* mybst = new BST();
    mybst->insert_node(2);
    mybst->insert_node(3);
    mybst->insert_node(1);
    mybst->insert_node(4);
    mybst->insert_node(0);
    cout << mybst->root->value << endl;
    cout << mybst->root->left->value << endl;
    cout << mybst->root->right->value << endl;
    cout << mybst->root->left->left->value << endl;
    cout << mybst->root->right->right->value << endl;
}