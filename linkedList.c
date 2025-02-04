#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

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

List* createList() {
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

int main() {
    List* lst = createList();
    for(int i=1;i<=5;i++) insertLast(lst, i);
    printList(lst);
    removeFront(lst);
    insertFront(lst,1);
    removeLast(lst);
    printList(lst);
    freeList(lst);
    return 0;
}
