#include <iostream>
#include "Header.h"

Tree::Tree()
{
    root = nullptr;
}

void Tree::makeSampleBST(int num)
{
    std::vector<int> arr;
    
    for (int i = 1; i <= num; i++)
        arr.push_back(i);

    root = makeBST(arr, 0, num - 1, root);
}

Node * Tree::makeBST(std::vector<int>& arr, int start, int end, Node * parent)
{
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    
    Node * newNode = new Node;
    newNode->parent = parent;
    newNode->data = arr[mid];
    newNode->left = makeBST(arr, start, mid - 1, newNode);
    newNode->right = makeBST(arr, mid + 1, end, newNode);
    
    return newNode;
}

void Tree::printTree(Node * root, std::string indent, bool last)
{
    if (root == nullptr) return;

    std::cout << indent;
    if (last)
    {
        std::cout << "R----";
        indent += "   ";
    }
    else
    {
        std::cout << "L----";
        indent += "|  ";
    }
    std::cout << root->data << std::endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
}
