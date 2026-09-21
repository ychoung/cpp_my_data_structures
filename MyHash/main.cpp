#include <iostream>
#include "hash.h"

int main(int argc, char const *argv[])
{
    hash<std::string, int> hashmap(8);

    hashmap["apple"] = 100;
    hashmap["apple"] = 60;
    // hashmap["apple2"] = 100;
    // hashmap["apple3"] = 100;
    // hashmap["apple4"] = 100;
    // hashmap["apple5"] = 100;
    // hashmap["apple6"] = 100;
    // hashmap["apple7"] = 100;
    // hashmap["apple8"] = 100;

    std::cout << hashmap["apple"] << std::endl;
    hashmap.erase("apple");
    std::cout << hashmap["apple"] << std::endl;
    return 0;
}
