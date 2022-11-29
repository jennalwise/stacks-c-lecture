# Stacks in C: Linked List Implementation
Lecture and active learning activities teaching stacks in C, focusing on linked list based stacks.
Between the interactive lecture and exercises, I cover the following learning goals:

* Understand the conceptual idea of Stacks
* Be able to recognize when to use a Stack to solve a programming problem
* Be able to use a Stack to solve a programming problem in C
* Be able to implement a Stack using a Linked List in C


# Review of Linked List Implementation Details

Linked lists are structures that hold data, like integers, strings, bools, and are **dynamically allocated**. That is, linked lists allocate and de-allocate storage during program execution and can grow and shrink as needed.

Conceptually, you can think of a linked list as a chain of structures called nodes, where each node contains data and a pointer to the next node. Below is an example visual of a linked list that contains four integers: 1, 6, 10, and 3. The end of the list is marked with a cross and denotes a NULL pointer.

<img src="images/linkedlist.png" alt="linked list" width="300"/>

Let's build up the concepts and code needed to implement the linked list shown in the image above.

## Declaring a Node Type
The first step in implementing a list is defining a `Node` data type, which contains data and a next pointer as described previously. In C code, this can be done with a typedef on a struct as seen below:

```C
typedef struct Node {
    int value; // data held in node, here that's an integer value
    struct Node* next;  // pointer to next node in the list
} Node;
```

## Empty List

Now that we have a `Node` data type we can implement an empty list easily, simply assign a Node pointer to `NULL`:

```C
Node* root = NULL;
```

Conceptually, this looks like:

<img src="images/emptylist.png" alt="emptylist" width="50"/>


## Creating a Node & Adding it to a List

The steps involved in creating and adding a node to a linked list are:

1. Allocating memory for a node
2. Storing data in the node
3. Inserting the node in the list

We will follow these steps to implement an `addNodeFirst` function, which takes the `root` of a list and an integer `item` to be inserted, creates and adds a node to the list with data item, and returns the resulting list:

```C
Node* addNodeFirst(Node* root, int item) {
    // allocate memory for a node
        // TODO
    // store data in the node
        // TODO
    // insert the node in the list
        // TODO
}
```

### Allocating Memory for a Node

To alloc memory for a node we can use malloc as given below:

```C
Node* addNodeFirst(Node* root, int item) {
    // allocate memory for a node
    Node* n = malloc(sizeof(struct Node));
    if (n == NULL) {
        // malloc failed & heap memory is full, error!
        return root;
    } else {
        // store data in the node
            // TODO
        // insert the node in the list
            // TODO
    }
}
```
As long as heap memory is not full, `malloc` will allocate a block of memory the size of the `Node` struct and the assignment will point `n` to that block of memory. 

<img src="images/add-allocate.png" alt="add allocate" width="125"/>

If `malloc` suceeds, then `n` will be non-null, otherwise `n == NULL` (i.e. when heap memory is exhausted by allocating all blocks of memory).
Since accessing a null pointer is bad (results in undefined behavior), we must handle this error case specially as seen above.



### Storing Data in Node

Once we have allocated memory for a node, we can store data in it, as seen in the `else` case below:

```C
Node* addNodeFirst(Node* root, int item) {
    // allocate memory for a node
    Node* n = malloc(sizeof(struct Node));
    if (n == NULL) {
        // malloc failed & heap memory is full, error!
        return root;
    } else {
        // store data in the node
        n->value = item;
        // insert the node in the list
            // TODO
    }
}
```

We have simply made the new node `n` contain `item`.

<img src="images/add-store.png" alt="add store" width="125"/>

### Inserting Node in List

Now, to insert `n` at the head/root or first in the list, we simply make node `n`'s next pointer point to the `root` node of the list.

<img src="images/add-insert1.png" alt="add insert1" width="300"/>

Then, we make `root` point to `n`'s node.

<img src="images/add-insert2.png" alt="add insert2" width="300"/>

So, our `addNodeFirst` function looks like this:

```C
Node* addNodeFirst(Node* root, int item) {
    // allocate memory for a node
    Node* n = malloc(sizeof(struct Node));
    if (n == NULL) {
        // malloc failed & heap memory is full, error!
        return root;
    } else {
        // store data in the node
        n->value = item;
        // insert the node in the list
        n->next = root;
        root = n;
        return root;
    }
}
```

Note, in the `else` case `root` is returned after insertion as `root` points to the new list after insertion.

<img src="images/add-result.png" alt="add result" width="300"/>

## Removing and Deleting a Node from a List
While not needed to create the list from the start of the section, being able to remove and delete a node from a list is important. This is especially true when we want to free all of our allocated memory after we are done with our list!

The steps for removing and deleting a node are as follows:
1. Locate the node to be deleted
2. Alter the previous node to bypass deleted node
3. Call `free` to reclaim space occupied by the deleted node

For simplicity let's focus on writing a function to find, remove, and delete the first node in the list given the list's root node. This function returns the resulting list after removal.

```C
Node* removeFirstNode(Node* root) {
    if (root == null)
        return root;
    // locate node to be deleted
        // TODO
    // alter previous node to bypass deleted node
        // TODO
    // call free to reclaim space
        // TODO
}
```

### Locate the Node to be Deleted

Since we are always removing the first integer in our list, location is simple. The node to be deleted is the one pointed to by `root`

<img src="images/remove-locate.png" alt="remove locate" width="300"/>

 and so let's point a temporary pointer `tmp` to the node as well

 <img src="images/remove-tmp.png" alt="remove tmp" width="300"/>

In code this looks like:

```C
Node* removeFirstNode(Node* root) {
    if (root == NULL)
        return root;
    // locate node to be deleted
    Node* tmp = root;
    // alter previous node to bypass deleted node
        // TODO
    // call free to reclaim space
        // TODO
}
```

### Alter Previous Node to Bypass Deleted Node

Since we are removing the node at the root/head of the list, there is not a previous node rather the `root` pointer is what we want to bypass the deleted node (i.e. you can think of the `root` pointer as the `next` pointer from the previous node).

<img src="images/remove-bypass.png" alt="remove bypass" width="300"/>

The code for this is below:

```C
Node* removeFirstNode(Node* root) {
    if (root == null)
        return root;
    // locate node to be deleted
    Node* tmp = root;
    // alter previous node to bypass deleted node
    root = root->next;
    // call free to reclaim space
        // TODO

    return root;
}
```
Note, `root` is returned by removeFirstNode, because it now points to the second node in the list, which means the first node has been removed.

<img src="images/remove-return.png" alt="remove return" width="200"/>

### Call free to Reclaim Space

Finally, we need to de-allocate memory from (delete) the node we just removed which is pointed to by `tmp`. That is, we simply call `free` on `tmp`.

<img src="images/remove-free.png" alt="remove free" width="300"/>

In code:
```C
Node* removeFirstNode(Node* root) {
    if (root == null)
        return root;
    // locate node to be deleted
    Node* tmp = root;
    // alter previous node to bypass deleted node
    root = root->next;
    // call free to reclaim space
    free(tmp);

    return root;
}
```
This is important to do so that we do not exhaust heap memory!

# Implementing a Stack with a Linked List

Recall, a **Stack** is an abstract data type (ADT) that holds a collection of data (integers, booleans, string, etc.) and preserves a First-In-Last-Out insertion and deletion strategy.

The Stack ADT interface looks like:

```

```

Recall that tracking the `top` of the stack is very important for `pop` and `push`.

Conceptually, we are always pushing elements onto the stack at the top and popping elements off of the top of the stack. Further, our top function returns the top element of the stack.

[visuals]

That's why we spent a lot of effort tracking `topPosition` correctly when implementing a Stack ADT based on an array.

So, it is not surprising that our Stack ADT also tracks the `top` of the stack, which for linked lists will be the `top` node in the list:

```C
typedef struct Stack {
    int size;  // tracks the size of the stack
    Node* top; // tracks the top node of the stack
} Stack;
```

Our Stack ADT also tracks its `size` for convenience.

*Question*: Where should our `top` node point to in a linked list? Head or tail of the linked list?

*Answer*: It doesn't matter as long as we respect the conceptual ideas of a stack and its functionality, especially in terms of pushing and popping!

For efficiency and convenience, let's make our `top` node always be the front/head of the list.

## Pushing onto the Stack

```C
bool push(Stack* s, int item) {
    if (stack is full) {
        // stack overflow error!
    } else {
        // add node to the top/front of the list
        // increase stack size
    }
}
```

## Popping off the Stack

```C
int pop(Stack* s) {
    if (stack is empty) {
        // stack underflow error!
    } else {
        // save data from top node to integer variable
        // remove & delete top node, aka the first element of the list
        // decrease stack size
        // return integer variable 
    }
}
```

## Peeking at the Top Element of the Stack

```C
int top(Stack* s) {
    if (stack is empty) {
        // stack underflow error!
    } else {
        // return data from the top node of the list
    }
}
```