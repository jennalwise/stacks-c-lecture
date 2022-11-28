#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"
#include "listStack.h"

/* Takes a stack s and initializes it, creating an empty Stack. 
*  Returns true or false depending on if initialization succeeded or failed.
*/
bool initialize(Stack* s) {
    // TODO
}

/* Returns true or false depending on whether the Stack contains any items or not. */
bool isEmpty(const Stack* s) {
    // TODO
}

/* Returns true or false depending on whether the Stack contains as much data as it can hold. */
bool isFull(const Stack* s) {
    // TODO
}

/* If the Stack is not full, push adds the specified item to the top of the Stack.
*  If the Stack is full, nothing is added, and an error is reported.
*/
bool push(Stack* s, int item) {
    // TODO
}

/* If the Stack is not empty, pop removes the top item from the stack and returns it.
*  If the Stack is empty, nothing is returned, and an error is reported.
*/
int pop(Stack* s) {
    // TODO
}

/* If the Stack is not empty, the top item is returned, but the contents of the Stack are not changed.
*  If the Stack is empty, nothing is returned, and an error is reported.
*/
int top(const Stack* s) {
    // TODO
}