#include <iostream>
#include <vector>
using namespace std;

// 4.2 Minimal Tree:
// Given a sorted (increasing order) array with unique integer elements,
// write an algorithm to create a binary search tree with minimal height.


struct Node
{
    int data;
    Node * left;
    Node * right;
};

Node * makeBST(vector<int>& arr, int start, int end)
{
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    
    Node * newNode = new Node;
    newNode->data = arr[mid];
    newNode->left = makeBST(arr, start, mid - 1);
    newNode->right = makeBST(arr, mid + 1, end);
    
    return newNode;
}

void printTree(Node *root, string indent = "", bool last = true)
{
    if (root == nullptr) return;

    cout << indent;
    if (last)
    {
        cout << "R----";
        indent += "   ";
    }
    else
    {
        cout << "L----";
        indent += "|  ";
    }
    cout << root->data << endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
}

int main()
{
    vector<int> arr = { 1, 2, 3, 4, 5 };
    Node * root = makeBST(arr, 0, 4);
    printTree(root);
}
