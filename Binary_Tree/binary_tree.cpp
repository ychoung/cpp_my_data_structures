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

            Node* parent = find_parent(current->rchild, newCurrent);

            if(parent == nullptr) // when parent is right above
            {
                parent = current;
                if(!newCurrent->rchild) // when new current has no righ children
                    current->rchild = nullptr;
            }
            else // when parent is not current
            {
                if(!newCurrent->rchild)
                    parent->lchild = nullptr;
            }

            if(newCurrent->rchild) // when new current has right child.
            {
                parent->lchild = newCurrent->rchild;
            }
        

            delete newCurrent; newCurrent = nullptr;
            return current;
        }

    }

    return current;
}

Node *BinaryTree::find_parent(Node* current, Node* child)
{
    if(current == nullptr)
        return nullptr;
    if(current->lchild == child)
        return current;
    
    return find_parent(current->rchild, child);
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
