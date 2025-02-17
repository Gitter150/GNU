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

void insertFront(List* lst, int x);
void insertLast(List* lst, int x);
List* new_List();
void freeList(List* lst);
void printList(List* lst);
void removeFront(List* lst);
void removeLast(List* lst);
int listLen(List* lst);
int indexOfNode(List* lst, Node* node);
Node* findNode(List* lst, int key);
Node* nodeAt(List* lst, int index);
dataResult dataAtNode(Node* node);