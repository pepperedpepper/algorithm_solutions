#include <iostream>
#include "Header.h"
using namespace std;

// 4.5 Validate BST:
// Implement a function to check if a binary tree is a binary search tree


bool validateBST(Node * root, int * min, int * max)
{
    if (root == nullptr) return true;
    
    if ((min != nullptr && root->data <= *min) || (max != nullptr && *max < root->data))
        return false;
        
    if (validateBST(root->left, min, &root->right->data) == false ||
        validateBST(root->right, &root->left->data, max) == false)
        return false;
    
    return true;
}


int main()
{
    Tree tree;
    tree.makeSampleBST(4);
    
    tree.printTree(tree.root);
    cout << (validateBST(tree.root, nullptr, nullptr) == true ? "TRUE" : "FALSE") << endl;

    Node * newNode = new Node;
    newNode->data = 11;
    tree.root->left->right = newNode;
    tree.printTree(tree.root);
    cout << (validateBST(tree.root, nullptr, nullptr) == true ? "TRUE" : "FALSE") << endl;
}
