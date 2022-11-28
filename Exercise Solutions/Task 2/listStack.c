#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "listStack.h"

/* Takes a stack s and initializes it, creating an empty Stack. 
*  Returns true or false depending on if initialization succeeded or failed.
*/
bool initialize(Stack* s) {
    if (s == NULL) {
        printf("ERROR: Malloc Stack before initializing!\n");
        return false;
    } else if (!isEmpty(s)) { 
        printf("ERROR: Initializing a non-empty Stack!\n");
        return false;
    } else {
        s->size = 0;
        s->top = NULL;
        return true;
    }
}

/* Returns true or false depending on whether the Stack contains any items or not. */
bool isEmpty(const Stack* s) {
    if (s == NULL) {
        return true;
    } else if (s->top == NULL) {
        return true;
    } else {
        return false;
    }
}

/* Returns true or false depending on whether the Stack contains as much data as it can hold. */
bool isFull(const Stack* s) {
    return false;
}

/* If the Stack is not full, push adds the specified item to the top of the Stack.
*  If the Stack is full, nothing is added, and an error is reported.
*/
bool push(Stack* s, int item) {
    if (isFull(s)) {
        printf("ERROR: Stack Overflow!\n");
        return false;
    } else if (s == NULL) {
        printf("ERROR: Malloc Stack before initializing!\n");
        return false;
    } else {
        Node* n = malloc(sizeof(struct Node));
        if (n == NULL) {
            printf("ERROR: Out of Heap Memory!\n");
            return false;
        } else {
            n->value = item;
            n->next = s->top;
        }
        s->top = n;
        s->size = s->size + 1;

        return true;
    }
}

/* If the Stack is not empty, pop removes the top item from the stack and returns it.
*  If the Stack is empty, nothing is returned, and an error is reported.
*/
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("ERROR: Stack Underflow!\n");
        return INT_MIN;
    } else {
        Node* tmp = s->top;
        int result = tmp->value;

        s->top = tmp->next;
        free(tmp);

        s->size = s->size - 1;
        
        return result;
    }
}

/* If the Stack is not empty, the top item is returned, but the contents of the Stack are not changed.
*  If the Stack is empty, nothing is returned, and an error is reported.
*/
int top(const Stack* s) {
    if (isEmpty(s)) {
        printf("ERROR: Stack Underflow!\n");
        return INT_MIN;
    } else {
        return s->top->value;
    }
}


/* Prints the contents of the Stack, prints the empty string if empty. */
void printHelper(Node* n) {
    if (n == NULL) {
        printf("\n");
    } else {
        printf("%i", n->value);
        printf(" ");
        printHelper(n->next);
    }
}

void print(const Stack* s) {
    if (isEmpty(s)) {
        printf("\n");
    } else {
        printHelper(s->top);
    }
}

/* Returns the size of the Stack. */
int size(const Stack* s) {
    if (s == NULL) {
        printf("ERROR: Stack pointer is NULL while checking size!\n");
        return INT_MIN;
    } else {
        return s->size;
    }
}