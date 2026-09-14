#include "binary_tree.h"

BinaryTree::BinaryTree()
{
    root = nullptr;
}

BinaryTree::~BinaryTree()
{
    destroy_tree(root);
}

Node* BinaryTree::insert_recursive_tree(Node* current, int val)
{
    if(current == nullptr)
    {
        return new Node(val);
    }

    if(val < current->data)
    {
        current->lchild = insert_recursive_tree(current->lchild, val);
    }
    else
    {
        current->rchild = insert_recursive_tree(current->rchild, val);
    }
    
    return current;
}

Node *BinaryTree::remove_recursive_tree(Node* current, int val)
{
    if(current == nullptr) return nullptr;

    if(val < current->data)
        current->lchild = remove_recursive_tree(current->lchild, val);
    else if(val > current->data)
        current->rchild = remove_recursive_tree(current->rchild, val);
    else
    {
        if(current->lchild == nullptr)
        {
            Node* newCurrent = current->rchild;
            delete current;
            return newCurrent;
        }
        else if(current->rchild == nullptr)
        {
            Node* newCurrent = current->lchild;
            delete current;
            return newCurrent;
        }
        else
        {
            Node* newCurrent = revised_inorder_traversal(current->rchild); // to get the smallest value that is greater than removed node
            
            current->data = newCurrent->data;

            current->rchild = remove_recursive_tree(current->rchild, newCurrent->data); // recursively visit the newCurrent node and delete it

            return current;
        }
    }

    return current;
}

Node *BinaryTree::find_lca(Node* current, int a, int b)
{
    if(current == nullptr) return nullptr;

    if(a < current->data && b < current->data)
        return find_lca(current->lchild, a, b);
    else if(a > current->data && b > current->data)
        return find_lca(current->rchild, a, b);
    else
    {
        return current;
    }

    return nullptr;
}

Node *BinaryTree::revised_inorder_traversal(Node* current)
{
    if (current->lchild == nullptr)
        return current;
    
    return revised_inorder_traversal(current->lchild);
}

void BinaryTree::inorder_traversal(Node* current)
{
    if(current == nullptr) return;

    inorder_traversal(current->lchild);
    
    std::cout << current->data << std::endl;

    inorder_traversal(current->rchild);
}

void BinaryTree::postorder_traversal(Node* current)
{
    if(current == nullptr) return;

    postorder_traversal(current->lchild);

    postorder_traversal(current->rchild);

    std::cout << current->data << std::endl;
}

void BinaryTree::destroy_tree(Node* current)
{
    if(current == nullptr) return;

    destroy_tree(current->lchild);

    destroy_tree(current->rchild);

    delete current; current = nullptr;
}

bool BinaryTree::find(Node* current, int val)
{
    if(current == nullptr)
        return false;

    if(current->data == val)
        return true;

    if(val < current->data)
        return find(current->lchild, val);
    else
        return find(current->rchild, val);

}

void BinaryTree::insert(int val)
{
    root = insert_recursive_tree(root, val);
}

void BinaryTree::remove(int val)
{
    root = remove_recursive_tree(root, val);
}

void BinaryTree::inorder()
{
    inorder_traversal(root);
}

void BinaryTree::postorder()
{
    postorder_traversal(root);
}

bool BinaryTree::search(int val)
{
    return find(root, val);
}

int BinaryTree::get_lca_value(int a, int b)
{
    if(root == nullptr) return -1; // error when root is empty

    if(!find(root, a) || !find(root, b)) return -1;

    Node* lca = find_lca(root, a, b);

    if(lca == nullptr) return -1; // error when find lca does not get common ancestor
    
    return lca->data;
}
