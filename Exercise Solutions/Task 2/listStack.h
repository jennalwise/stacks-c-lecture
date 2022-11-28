/*
    Header file for defining shared listStack structs
    
    Author: Jenna DiVincenzo
*/

typedef struct Node {
    int value;
    struct Node* next;
} Node;

/* Stack abstract data type */
typedef struct Stack {
    int size;
    Node* top;
} Stack;