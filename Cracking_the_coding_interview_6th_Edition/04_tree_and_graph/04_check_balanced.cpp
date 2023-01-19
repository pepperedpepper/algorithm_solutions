#include <iostream>
#include <algorithm>
#include "Header.h"
using namespace std;

// 4.4 Check Balanced:
// Implement a function to check if a binary tree is balanced.
// For the purposes of this question, a balanced tree is defined to be a tree such that
// the heights of the two subtrees of any node never differ by more than one.


int getHeight(Node * root)
{
    if (root == nullptr) return -1;
    
    return max(getHeight(root->right), getHeight(root->left)) + 1;
}

bool checkBalanced(Node * root)
{
    if (root == nullptr) return true;
        
    int right = getHeight(root->right);
    int left = getHeight(root->left);
    
    if (1 < abs(right - left)) return false;

    return checkBalanced(root->right) && checkBalanced(root->left);
}


int main()
{
    Tree tree;
    
    Tree sub;
    sub.makeSampleBST(5);
    
    tree.root = new Node;
    tree.root->data = 0;
    tree.root->right = sub.root;
    cout << (checkBalanced(tree.root) == true ? "TRUE" : "FALSE") << endl;
    
    tree.makeSampleBST(5);
    cout << (checkBalanced(tree.root) == true ? "TRUE" : "FALSE") << endl;
    
}
