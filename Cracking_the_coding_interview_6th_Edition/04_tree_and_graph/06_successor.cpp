#include <iostream>
#include "Header.h"
using namespace std;

// 4.6 Successor:
// Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree.
// You may assume that each node has a link to its parent.

Node * getMostLeft(Node * root)
{
    while(root->left != nullptr)
        root = root->left;
    
    return root;
}

Node * getSuccessor(Node * root)
{
    if (root == nullptr) return nullptr;
    
    if (root->right != nullptr)
        return getMostLeft(root->right);
    
    Node* child = root;
    Node* ancestor = root->parent;
    
    while (ancestor != nullptr && ancestor->right == child)
    {
        child = ancestor;
        ancestor = child->parent;
    };
    
    return ancestor;
}


int main()
{
    Tree tree;
    tree.makeSampleBST(10);
    tree.printTree(tree.root);
    
    Node * node = getSuccessor(tree.root->left);
    if (node == nullptr)
        cout << "NULL" << endl;
    else
        cout << node->data << endl;
}
