#include <iostream>

class BinaryTree {
    private:
    class Node {
        public:
        int data;
        Node* left;
        Node* right;
        Node(int x): data(x), left(nullptr), right(nullptr) {}
    };
    Node* root;
    void addNode(Node* &current, int x) {  // BST add node function
        if(current == nullptr) {
            current = new Node(x);
        } else if(x < current -> data) {
            addNode(current -> left, x);
        } else {
            addNode(current -> right, x);
        }
    }
    void printInOrder(Node*& current) {
        if(current == nullptr) {
            return;
        }
        printInOrder(current -> left);
        std::cout<<current -> data<<" ";
        printInOrder(current -> right);
    }
    public:
    BinaryTree(): root(nullptr) {}
    void add(int value) {
        addNode(this->root, value);
    }
    void print() {
        printInOrder(root);
        std::cout<<std::endl;
    }
};

int main() {
    BinaryTree t;
    t.add(10);
    t.add(12);
    t.add(-5);
    t.add(-6);
    t.add(0);
    t.add(5);
    t.add(2);
    t.add(3);
    t.add(1);
    t.print();
    return 0;
}