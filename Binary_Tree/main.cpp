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

    std::cout << tree.get_lca_value(20,30) << std::endl;

    // std::cout << "LCA of 20 and 40: " << tree.get_lca_value(20, 40) << std::endl; // 30 출력 예상
    // std::cout << "LCA of 20 and 70: " << tree.get_lca_value(20, 70) << std::endl; // 50 출력 예상
    // std::cout << "LCA of 30 and 40: " << tree.get_lca_value(30, 40) << std::endl;

    return 0;
}


