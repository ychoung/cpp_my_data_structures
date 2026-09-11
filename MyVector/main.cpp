#include <iostream>
#include "my_vector.h"

int main(int argc, char const *argv[])
{
    MyVector vector;

    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);

    std::cout << vector.at(2) << std::endl;
    return 0;
}
