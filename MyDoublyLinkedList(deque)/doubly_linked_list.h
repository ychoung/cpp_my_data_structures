#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev; 

    Node(int val, Node* nxt = nullptr, Node* prv = nullptr) {
        data = val;
        next = nxt;
        prev = prv;
    }
};

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;

public:
    // Constructor: Initializes an empty list
    DoublyLinkedList();

    // Destructor: Traverses the list and deallocates every dynamically allocated node
    ~DoublyLinkedList();

    // Core Method 1: Prepends a new node to the front of the list
    void push_front(int);

    // Core Method 2: Traverses and prints all node values for debugging
    void print_all() const;

    void print_reverse() const;

    void push_back(int);

    void pop_front();
    
    void pop_back();

    void insert(Node*, int);

    void erase(Node*);

    void clear();

};

#endif