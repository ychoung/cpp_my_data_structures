#include "binary_tree.h"

int main(int argc, char const *argv[])
{
    BinaryTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.insert(65);

    tree.remove(50);
    tree.inorder();

    return 0;
}
