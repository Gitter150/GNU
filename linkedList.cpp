#include <iostream>

class LinkedList {
public:
    class Node {
    public:
        Node* next;
        Node* prev;
        int data;
        Node(int data) {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };
    Node* head;
    Node* tail;
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList() {
        Node* current = head;   
        while(current != nullptr) {
            Node* nextPtr = current -> next;
            delete current;
            current = nextPtr;
        } 
    }
    
    void push_front(int x) {
        if(head == nullptr){
            head = new Node(x);
            tail = head;
            return;
        } // checking head is enough since head == null <=> tail == null
        head -> prev = new Node(x);  // head -> prev points to new head now!
        head -> prev -> next = head;
        head = head -> prev;
    }
    void print() {
        Node* current = head;
        while (current != tail) {
            std::cout << current->data << " <-> ";
            current = current -> next;
        } //prints all nodes but the last one (that is, the tail) with the double sided arrow symbol infront of them to indicate doubly linked list ( that's right its a DLL )
        std::cout << current->data << "\n"; //finally prints last node with a newline at the end for robustness of the function 
    }
};
LinkedList::Node* addOne(LinkedList::Node* head) {
    // reverse
    LinkedList::Node *currNode=head, *prevNode=nullptr, *nextNode;
    int flag = 0;
    while(currNode) {
        nextNode = currNode -> next;
        currNode -> next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    head = prevNode;
    // reverse end
    currNode = head;
    while(currNode->next) {
        if(currNode->data==9) {
            currNode->data = 0;
        }
        else {
            currNode->data += 1;
            flag = 1; // flag=1 means addition is completed. 
            break;
        }
        currNode = currNode->next;
    }
    if(!flag) {
        if(currNode->data==9) {
            currNode->next = new LinkedList::Node(1);
        }
        else {
            currNode->data+=1;
        }
    }
    currNode = head;
    prevNode = nullptr;
    while(currNode) {
        nextNode = currNode -> next;
        currNode -> next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    return prevNode;
}

int main() {
    LinkedList lst = LinkedList();
    lst.push_front(9);
    lst.head = addOne(lst.head);
    lst.print();
    return 0;
}
