#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "stack.h"
#include "listStack.h" // Can use arrayStack header here and tests will work!

/*
    File for testing the listStack ADT

    Author: Jenna DiVincenzo
*/


void test_isEmpty_null_stack() {
    Stack* s = NULL;
    assert(isEmpty(s));
}

void test_isEmpty_nonempty_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    initialize(s);
    assert(isEmpty(s));
    push(s,3);
    assert(!isEmpty(s));
}

void test_initialize_null_stack() {
    Stack* s = NULL;
    bool success = initialize(s);
    assert(!success);
}

void test_initialize_malloc_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    bool success = initialize(s);
    assert(success);
    assert(isEmpty(s));
}

void test_initialize_nonempty_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    bool success = initialize(s);
    assert(success);
    push(s,3);
    success = initialize(s);
    assert(!success);
}

void test_isFull_null_stack() {
    Stack* s = NULL;
    assert(!isFull(s));
}

void test_isFull_malloc_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    assert(!isFull(s));
}

void test_isFull_nonempty_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    bool success = initialize(s);
    assert(success);
    push(s,3);
    assert(!isFull(s));
}

void test_push_null_stack() {
    Stack* s = NULL;
    assert(!push(s,3));
}

void test_push_malloc_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    initialize(s);
    assert(push(s,3));
    assert(top(s) == 3);
}

void test_push_nonempty_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    initialize(s);
    assert(push(s,3));
    assert(top(s) == 3);
    assert(push(s,10));
    assert(top(s) == 10);
}

void test_pop_null_stack() {
    Stack* s = NULL;
    assert(pop(s) == INT_MIN);
}

void test_pop_malloc_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    initialize(s);
    assert(pop(s) == INT_MIN);
}

void test_pop_nonempty_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    initialize(s);
    assert(push(s,3));
    assert(top(s) == 3);
    assert(pop(s) == 3);
    assert(push(s,3));
    assert(top(s) == 3);
    assert(push(s,10));
    assert(top(s) == 10);
    assert(pop(s) == 10);
    assert(top(s) == 3);
}

void test_top_null_stack() {
    Stack* s = NULL;
    assert(top(s) == INT_MIN);
}

void test_top_malloc_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    initialize(s);
    assert(top(s) == INT_MIN);
}

void test_print_null_stack() {
    Stack* s = NULL;
    print(s);
}

void test_print_empty_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    initialize(s);
    print(s);
}

void test_print_nonempty_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    initialize(s);
    assert(push(s,3));
    assert(push(s,5));
    assert(push(s,10));
    print(s);
    assert(pop(s) == 10);
    print(s);
    assert(pop(s) == 5);
    print(s);
}

void test_size_null_stack() {
    Stack* s = NULL;
    assert(size(s) == INT_MIN);
}

void test_size_empty_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    initialize(s);
    assert(size(s) == 0);
}

void test_size_nonempty_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    initialize(s);
    assert(size(s) == 0);
    assert(push(s,3));
    assert(size(s) == 1);
    assert(pop(s) == 3);
    assert(size(s) == 0);
    assert(push(s,3));
    assert(size(s) == 1);
    assert(push(s,10));
    assert(size(s) == 2);
    assert(pop(s) == 10);
    assert(size(s) == 1);
}

void stackSort(Stack* src) {
    // only sort the stack if non-empty
    if (!isEmpty(src)) {
        // Create and initializes two other stacks
        Stack* tmp = malloc(sizeof(struct Stack));
        assert(initialize(tmp));
        Stack* dest = malloc(sizeof(struct Stack));
        assert(initialize(dest));

        // Use the three stacks to sort the elements in dest from 
        // largest on the bottom to smallest on top
        while (!isEmpty(src)) {
            while (!isEmpty(dest) && top(src) > top(dest)) {
                int destItem = pop(dest);
                assert(push(tmp, destItem));
            }
            int srcItem = pop(src);
            assert(push(dest, srcItem));
            while (!isEmpty(tmp)) {
                int tmpItem = pop(tmp);
                assert(push(dest, tmpItem));
            }
        }

        // Put all the elements back into source from dest,
        // so source is sorted from smallest on the bottom to largest on the top
        while (!isEmpty(dest)) {
            int destItem = pop(dest);
            assert(push(src, destItem));
        }

        free(tmp);
        free(dest);
    }
}

void test_stackSort() {
    Stack* s = malloc(sizeof(struct Stack));
    initialize(s);
    assert(push(s,3));
    assert(push(s,3));
    assert(push(s,10));
    assert(push(s,5));
    assert(push(s,7));
    assert(push(s,2));
    assert(push(s,9));
    print(s);
    stackSort(s);
    print(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    free(s);
}

int main(void) {

    printf("Testing initialize and isEmpty.\n");
    test_initialize_null_stack();
    test_isEmpty_null_stack();
    test_initialize_malloc_stack();
    test_initialize_nonempty_stack();
    test_isEmpty_nonempty_stack();

    printf("\n");
    printf("Testing isFull.\n");
    test_isFull_null_stack();
    test_isFull_malloc_stack();
    test_isFull_nonempty_stack();

    printf("\n");
    printf("Testing push.\n");
    test_push_null_stack();
    test_push_malloc_stack();
    test_push_nonempty_stack();

    printf("\n");
    printf("Testing pop.\n");
    test_pop_null_stack();
    test_pop_malloc_stack();
    test_pop_nonempty_stack();

    printf("\n");
    printf("Testing top.\n");
    test_top_null_stack();
    test_top_malloc_stack();

    printf("\n");
    printf("Testing print.\n");
    test_print_null_stack();
    test_print_empty_stack();
    test_print_nonempty_stack();

    printf("\n");
    printf("Testing size.\n");
    test_size_null_stack();
    test_size_empty_stack();
    test_size_nonempty_stack();

    printf("\n");
    printf("Testing stackSort.\n");
    test_stackSort();

    printf("\n");
    printf("TESTING SUCEEDED YAY!\n");

    return 0;
}