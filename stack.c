/*
* WARNING!!!!!!!!!!!!!!!!!!
* COMPILE THIS PROGRAM USING THE BELOW COMMAND AND RUN AS USUAL
* gcc stack.c list_without_main.c -o a 
*/

#include <stdio.h>          
#include "list.h"
#include <stdlib.h>         
typedef List Stack;         
Stack* new_Stack();
void push(Stack*, int);
void pop(Stack*);
int peek(Stack*);
void printStack(Stack*);

int main() {
    Stack* stk = new_Stack();
    push(stk, 1);
    push(stk, 2);
    push(stk, 3);
    printStack(stk);
    pop(stk);
    printStack(stk);
}

Stack* new_Stack() {
    return new_List();
}

void push(Stack* stk, int x){
    insertFront(stk, x);
}

void pop(Stack* stk){
    if(stk -> head == NULL) {
        printf("Stack is already empty! Nothing to remove here...\n");
        return;
    }
    Node* front = stk -> head;
    stk -> head = (stk -> head) -> next;
    free(front);
}

int peek(Stack* stk) {
    if(stk -> head == NULL) {
        printf("Stack is already empty! Nothing to peek..\n");
        return -9999;                // I know weird error code lmfao but who cares
    }
    return (stk -> head) -> data;
}

void printStack(Stack* stk) {
    printList(stk);
}
