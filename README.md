# Stacks in C
Lecture and active learning activities teaching stacks in C, focusing on linked list based stacks.
Between the interactive lecture and exercises, I cover the following learning goals:

* Understand the conceptual idea of Stacks
* Be able to recognize when to use a Stack to solve a programming problem
* Be able to use a Stack to solve a programming problem in C
* Be able to implement a Stack using an Array in C
* Be able to implement a Stack using a Linked List in C
* Be able to defend the decision to use an Array or a Linked List to implement a Stack

## Interactive Lecture: Slides & Recording

You can find both the slides with notes and a recording of me presenting the slides, here: [TBD] . 

## Exercises for Practice

***

### Task 1: Deciding On & Defending Use of Stack

Individually, write down whether a stack is appropriate for each of the following tasks, and indicate why or why not:

<ol type = "a">
    <li> 
    A word-processing program must remember a line of up to 80 characters. Pressing the Backspace key deletes the previous character, and pressing Ctrl+Backspace deletes the entire line. Users must be able to undo deletion operations.
    </li> 
    <li>
    Customers must wait one to three months for delivery of their new cars. The dealer creates a list to determine the "fair" order in which customers should get their cars; the list is prepared in the order in which customers places their requests for a new car.
    </li>
    <li>
    You're required to search downward in a pile of magazines to locate the issue for last January. Each magazine was placed on the pile as soon as it was received.
    </li>
    <li>
    A programming team accepts jobs and prioritizes them on the basis of urgency.
    </li>
    <li>
    A line forms at a bus stop.
    </li>
</ol>

Then, share your results with 1-2 neighbors. After, we will go over the answers as a class.

**Note**: This exercise comes from *A First Book of C++, by Gary Bronson*.

***

### Paired Programming
The rest of the exercises you will be working on will involve paired programming with a partner of your choice.
As a reminder here is how paired programming works: TBD

***

### Task 2: Implementing a Linked List Based Stack

Part A
1. Fill in the missing implementation details in `listStack.c` and `listStack.h` given in the Exercise Starter Code folder for Task 2. Missing details are marked by `// TODO` comments. *Note, you are implementing the Stack interface for integers with a Linked List in this task*.
2. Compile, run, and test your code by running the following commands in the Task 2 Directory:
    ```
    make
    ./test
    ```
    Make sure your implementation passes all test cases, aka. you should see `TESTING SUCEEDED YAY!` in you console and execution should not abort.

    You can clean up your directory at anytime by running: `make clean`.

Part B
1. Add a function to your list based Stack that prints the contents of the stack called `print`. *Hint, you will need to add a function definition to the `stack.h` header file and implement it in the `listStack.c` file*.
    * Write 1-2 test cases for `print` by adding them to the `test.c` file. 
    The test cases should create and modify a Stack with your implemented operations and print the resulting Stack. You can print after each call to push, pop, top, etc. if you'd like. Visually inspect the results for correctness. (OPTIONAL: Feel free to utilize C assertions to ensure correctness). 
    
2. Add a function that returns the current size of the Stack called `size`.
    * Write 1-2 test cases for your Stack that ensures the size is correctly tracked as elements are pushed, popped, and inspected with top. Add the test cases to `test.c` as you did for `print`. This time use C assertions as done in the `test.c` file to make sure the size is correct as you are modifying the Stack.

**Note**: This exercise is inspired by *Barbara Johnson's lab exercise on Linked List based Stacks*.

***

### Task 3: Linked List Stack Tracking the Min Element

We can design a stack, which in addition to `push` and `pop`, also has a function `min` which returns the minimum element in the stack. We could do this by iterating over our internal linked list, keeping track of the minimal element, and returning it from `min`. But, this strategy is expensive when our list/stack contains many elements (O(n)---linear time, where n is the number of elements in our stack), because we are iterating over all of them. We do not have to iterate over the list to `push` or `pop` elements on or off the stack, we just work with two nodes at most at anytime, which is not expensive at all (O(1)---constant time)!

Can you augment the design of your list based stack to track and return the minimum element in the stack without iterating over the list? That is, `pop`, `push`, and `min` should all operate in constant time (O(1)).

*Hints:*

* *Have each node record what the minimum beneath itself is. Then, to find the min, you just look at what the top element thinks is the min.*
* *You will need to augment your operations on the stack, like `pop` and `push`, to track min on each node properly.*
* *Augment `listStack.c` and `listStack.h` with the changes and make sure `stack.h` defines `min` abstractly for use.*
* *You do not need to write test cases, just make sure `test.c` executes successfully as is from Task 2.*

**OFFLINE CHALLENGE**: Tracking the min for every single element in the stack is expensive space wise, so can you do better? *Hint, you can use an additional stack which keeps track of the mins rather than storing them in every node to solve this problem.*

**Note**: This exercise is comes from *Cracking the Coding Interview: 150 Programming Questions and Solutions, by Gayle Laakmann McDowell*.

***

### Task 4

Write a program to sort a stack in ascending order (with biggest items on top) using three stacks (including the original stack to be sorted, so two additional stacks). Use your Stack abstract data type as a user would, pretending not to know how its implemented and only relying on stack operations defined in `stack.h`.

You can implement this program in `test.c` as a function called `stackSort`. Then, create a test case/function that creates a stack, prints the contents, calls `stackSort` to sort the stack, and prints the contents after sorting. Make sure the console output is functionally correct, aka. the stack is sorted properly.

**OFFLINE CHALLENGE**: Try to do this with only one additional stack, for a total of two stacks.

**Note**: This exercise is inspired by a similar exercise in *Cracking the Coding Interview: 150 Programming Questions and Solutions, by Gayle Laakmann McDowell*.