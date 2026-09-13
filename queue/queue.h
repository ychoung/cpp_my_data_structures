#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

// Represents an individual node in the singly linked list
struct Node {
    int data;           // The payload value
    Node* next;         // Pointer to the next node in the sequence
};

class Queue {
private:
    Node* head;    // Pointer to the first node (entry point of the list)
    Node* tail;

public:
    // Constructor: Initializes an empty list
    Queue();

    // Destructor: Traverses the list and deallocates every dynamically allocated node
    ~Queue();

    // Core Method 1: Prepends a new node to the front of the list
    void push(int);
    
    void pop();

    void print_all();

};

#endif