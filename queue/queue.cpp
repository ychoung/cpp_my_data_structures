#include "queue.h"

Queue::Queue()
{
    head = tail = nullptr;
}

Queue::~Queue()
{
    while(head != nullptr)
    {
        pop();
    }
}

void Queue::push(int value)
{
    if(head == nullptr)
    {
        head = tail = new Node{value, nullptr};
        return;
    }

    Node* newNode = new Node{value, nullptr};
    tail->next = newNode;
    tail = newNode;

}

void Queue::pop()
{
    if(head == nullptr) return; // queue is empty

    if(head == tail)
    {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node* removed = head;
    head = head->next;

    delete removed; removed = nullptr;
}

void Queue::print_all()
{
    if(head == nullptr) return;

    Node* tmp = head;

    while(tmp != nullptr)
    {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }

}
