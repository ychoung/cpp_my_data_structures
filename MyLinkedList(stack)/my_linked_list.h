#ifndef MY_LINKED_LIST_H
#define MY_LINKED_LIST_H

#include <iostream>

// Represents an individual node in the singly linked list
struct Node {
    int data;           // The payload value
    Node* next;         // Pointer to the next node in the sequence
};

class MyLinkedList {
private:
    Node* head;    // Pointer to the first node (entry point of the list)

public:
    // Constructor: Initializes an empty list
    MyLinkedList();

    // Destructor: Traverses the list and deallocates every dynamically allocated node
    ~MyLinkedList();

    // Core Method 1: Prepends a new node to the front of the list
    void push_front(int value);

    // Core Method 2: Traverses and prints all node values for debugging
    void print_all() const;

    void push_back(int value);

    void pop_front();
    
    void pop_back();

    int top();

    bool is_empty();
};

#endif