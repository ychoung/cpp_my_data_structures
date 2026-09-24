#include <iostream>

#include "hash.h"
#include "my_vector.h"

int main(int argc, char const *argv[])
{
    hash<std::string, MyVector<MyVector<int>>> graph(1);
    // MyVector<int> v1;
    // MyVector<int> v2 = v1;

    graph["G1"];
    return 0;
}
