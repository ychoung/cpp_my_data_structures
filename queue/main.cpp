#include "queue.h"

int main(int argc, char const *argv[])
{
    Queue q;

    q.push(0);
    q.push(3);
    q.push(5);
    q.push(6);
    q.pop();
    q.print_all();
    
    return 0;
}
