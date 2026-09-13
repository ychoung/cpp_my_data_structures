#include <iostream>

int factorial(int);

int fibonacci(int);

int main(int argc, char const *argv[])
{
    std::cout << fibonacci(6) << std::endl;
    return 0;
}

int factorial(int n)
{
    if(n <= 1) return 1;

    return n * factorial(n - 1);
}

int fibonacci(int n)
{
    if(n <= 0) return 0;
    if(n <= 2) return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}