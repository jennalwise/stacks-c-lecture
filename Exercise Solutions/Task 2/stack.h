/*
  Stack interface, for a Stack containing integers

  Author: Jenna DiVincenzo
*/

/* Stack abstract data type */
typedef struct Stack Stack;

/* Takes a stack s and initializes it, creating an empty Stack. 
*  Returns true or false depending on if initialization succeeded or failed.
*/
bool initialize(Stack* s);

/* Returns true or false depending on whether the Stack contains any items or not. */
bool isEmpty(const Stack* s);

/* Returns true or false depending on whether the Stack contains as much data as it can hold. */
bool isFull(const Stack* s);

/* If the Stack is not full, push adds the specified item to the top of the Stack.
*  If the Stack is full, nothing is added, and an error is reported.
*/
bool push(Stack* s, int item);

/* If the Stack is not empty, pop removes the top item from the stack and returns it.
*  If the Stack is empty, nothing is returned, and an error is reported.
*/
int pop(Stack* s);

/* If the Stack is not empty, the top item is returned, but the contents of the Stack are not changed.
*  If the Stack is empty, nothing is returned, and an error is reported.
*/
int top(const Stack* s);

/* Prints the contents of the Stack, prints the empty string if empty. */
void print(const Stack* s);

/* Returns the size of the Stack. */
int size(const Stack* s);