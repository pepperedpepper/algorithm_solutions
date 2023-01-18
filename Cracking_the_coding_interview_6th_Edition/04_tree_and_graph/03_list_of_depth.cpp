#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 4.3 List of Depths:
// Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth
// (e.g., if you have a tree with depth D, you'll have D linked lists).


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

void createLevelLinkedLists(Node * curNode, vector<list<Node *>>& lists, int level)
{
    if (curNode == nullptr) return;
    
    if (lists.size() <= level)
    {
        list<Node *> curList;
        lists.push_back(curList);
    }
    
    lists[level].push_back(curNode);
    
    createLevelLinkedLists(curNode->left, lists, level + 1);
    createLevelLinkedLists(curNode->right, lists, level + 1);
}

void printLinkedLists(vector<list<Node *>>& lists)
{
    for (int i = 0; i < lists.size(); i++)
    {
        list<Node *> li = lists[i];
        list<Node *>::iterator it;
        
        cout << "Lev " << i << " : ";
        
        for (it = li.begin(); it!=li.end(); it++)
        {
            Node * ptr = *it;
            cout << ptr->data << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Node * root = makeBST(arr, 0, 9);
    printTree(root);
    
    vector<list<Node *>> lists;
    createLevelLinkedLists(root, lists, 0);
    printLinkedLists(lists);
}
