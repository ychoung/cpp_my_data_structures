#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>

struct Node
{
    int data;
    Node* lchild;
    Node* rchild;

    Node(int value, Node* left = nullptr, Node* rigth = nullptr)
    {
        data = value;
        lchild = left;
        rchild = rigth;
    }

};

class BinaryTree
{
private:
    Node* root;

    Node* insert_recursive_tree(Node*, int);

    Node* revised_inorder_traversal(Node*);

    Node* remove_recursive_tree(Node*, int);

    Node* find_lca(Node*, int, int); // find lowest common ancestor

    void inorder_traversal(Node*);

    void postorder_traversal(Node*);

    void destroy_tree(Node*); 

    bool find(Node*, int);

    

public:
    BinaryTree();
    
    ~BinaryTree();

    void insert(int);

    void remove(int);

    void inorder();

    void postorder();

    bool search(int);

    int get_lca_value(int, int);
};

#endif