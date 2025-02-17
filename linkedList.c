#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

typedef struct {
    int success;
    int data;
} dataResult;

void insertFront(List* lst, int x){
    Node* first = (Node*)malloc(1*sizeof(Node));
    if (first) {
        first -> next = lst -> head;
        first -> data = x;
        lst -> head = first;
    }
    else printf("Memory Allocation for the new Node failed!\n");
}

void insertLast(List* lst, int x){
    Node* last = (Node*)malloc(1*sizeof(Node));

    if(!last){
        printf("Memory Allocation for the new Node has failed! Terminating..\n");
        return;
    }
    
    last -> data = x;
    last -> next = NULL;

    if(lst -> head == NULL){
        lst -> head = last;
        return;
    }
    
    Node* nextPtr = lst -> head;
    while(nextPtr -> next != NULL){
        nextPtr = nextPtr -> next;
    }
    nextPtr -> next = last;
}

List* new_List() {
    List* lst = (List*)malloc(1 * sizeof(List));
    if (lst) lst -> head = NULL;
    else printf("Memory Allocation for the new List object failed!\n");
    return lst;
}

void freeList(List* lst) {
    Node* current = lst->head;
    while (current) {
        Node* temp = current;  // Store the current node
        current = current->next;  // Move to the next node
        free(temp);  // Free the stored node
    }
    free(lst);  // Finally, free the List struct
}

void printList(List* lst){
    Node* current = (lst -> head);
    if(current == NULL) {
        printf("The given list is empty! Nothing to print here..\n");
        return;
    }
    while(current){
        printf("-> %d ",current -> data);
        current = current -> next;
    }
    printf("\n");
}

void removeFront(List* lst) {
    if(lst -> head == NULL) {
        printf("Linked List is already empty! Nothing to remove here...\n");
        return;
    }
    Node* front = lst -> head;
    lst -> head = (lst -> head) -> next;
    free(front);
}

void removeLast(List* lst){
    if(lst -> head == NULL){
        printf("List is empty! Nothing to delete here..\n");
        return;
    }
    if((lst -> head) -> next == NULL){
        Node* temp = lst -> head;
        lst -> head = NULL;
        free(temp);
        return;
    }
    Node* nextPtr = lst -> head;
    while((nextPtr -> next) -> next != NULL){
        nextPtr = nextPtr -> next;
    }
    Node* temp = nextPtr -> next;
    nextPtr -> next = NULL;
    free(temp);
}

int listLen(List* lst){
    int len = 0;
    Node* current = lst -> head;
    while(current != NULL) {
        len++;
        current = current -> next;
    }
    return len;
}

int indexOfNode(List* lst, Node* node) {
    int index = 0;
    Node* current = lst -> head;
    while(current) {
        if(current == node) return index;
        index++;
        current = current -> next;
    }
    return -1;
}

Node* findNode(List* lst, int key) {
    Node* foundNode = lst -> head;
    while(foundNode) {
        if(foundNode -> data == key){
            return foundNode;
        }
        foundNode = foundNode -> next;
    }
    return NULL;
}

Node* nodeAt(List* lst, int index) {
    int i = 0;
    Node* current = lst -> head;
    while(current) {
        if(i == index) return current;
        i++;
        current = current -> next;
    }
    return NULL;
}
/*
void reverseList(List* lst) {             
    if(lst -> head == NULL) {
        return;
    }
    if((lst -> head) -> next == NULL) {    fellow programmer,
        return;                            please, if this function is marked as a comment,
    }                                      please, complete it and push the file to my
                                           main branch. Thank you. 
} */

dataResult dataAtNode(Node* node) {
    if(!node) {
        return (dataResult) { .success = 0 , .data = 0};  //error code
    }
    return (dataResult) { .success = 1, .data = node -> data};
}

int main() {
    List* lst = new_List();
    int index = 0;
    for(int i=1;i<=5;i++) insertLast(lst, i);
    printList(lst);
    removeFront(lst);
    insertFront(lst,1);
    removeLast(lst);
    printList(lst);
    printf("The length of the list is %zu\n",listLen(lst));
    printf(dataAtNode(nodeAt(lst, index)).success? "The data at node of index %d is %d\n":"Error! Node doesn't exist\n",index,dataAtNode(nodeAt(lst, index)).data);
    freeList(lst);
    return 0;
}
