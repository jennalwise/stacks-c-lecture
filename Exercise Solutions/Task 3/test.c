#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "stack.h"
#include "listStackWithMin.h" // Can use arrayStack header here and tests will work!

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

    pop(s);
    free(s);
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

    free(s);
}

void test_initialize_nonempty_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    bool success = initialize(s);
    assert(success);
    push(s,3);
    success = initialize(s);
    assert(!success);

    pop(s);
    free(s);
}

void test_isFull_null_stack() {
    Stack* s = NULL;
    assert(!isFull(s));
}

void test_isFull_malloc_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    assert(!isFull(s));

    free(s);
}

void test_isFull_nonempty_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    bool success = initialize(s);
    assert(success);
    push(s,3);
    assert(!isFull(s));

    pop(s);
    free(s);
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

    pop(s);
    free(s);
}

void test_push_nonempty_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    initialize(s);
    assert(push(s,3));
    assert(top(s) == 3);
    assert(push(s,10));
    assert(top(s) == 10);

    pop(s);
    pop(s);
    free(s);
}

void test_pop_null_stack() {
    Stack* s = NULL;
    assert(pop(s) == INT_MIN);
}

void test_pop_malloc_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    initialize(s);
    assert(pop(s) == INT_MIN);

    free(s);
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

    pop(s);
    free(s);
}

void test_top_null_stack() {
    Stack* s = NULL;
    assert(top(s) == INT_MIN);
}

void test_top_malloc_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    initialize(s);
    assert(top(s) == INT_MIN);

    free(s);
}

void test_print_null_stack() {
    Stack* s = NULL;
    print(s);
}

void test_print_empty_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    initialize(s);
    print(s);

    free(s);
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

    pop(s);
    free(s);
}

void test_size_null_stack() {
    Stack* s = NULL;
    assert(size(s) == INT_MIN);
}

void test_size_empty_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    initialize(s);
    assert(size(s) == 0);
    
    free(s);
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

    pop(s);
    free(s);
}

void test_min_null_stack() {
    Stack* s = NULL;
    assert(min(s) == INT_MAX);
}

void test_min_empty_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    initialize(s);
    assert(min(s) == INT_MAX);

    free(s);
}

void test_min_nonempty_stack() {
    Stack* s = malloc(sizeof(struct Stack));
    initialize(s);
    assert(min(s) == INT_MAX);
    assert(push(s,3));
    assert(min(s) == 3);
    assert(pop(s) == 3);
    assert(min(s) == INT_MAX);
    assert(push(s,3));
    assert(min(s) == 3);
    assert(push(s,10));
    assert(min(s) == 3);
    assert(push(s,2));
    assert(min(s) == 2);
    assert(pop(s) == 2);
    assert(min(s) == 3);

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
    printf("Testing min.\n");
    test_min_null_stack();
    test_min_empty_stack();
    test_min_nonempty_stack();

    printf("\n");
    printf("TESTING SUCEEDED YAY!\n");

    return 0;
}