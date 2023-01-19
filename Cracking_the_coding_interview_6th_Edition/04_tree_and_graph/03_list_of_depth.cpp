#include <iostream>
#include <vector>
#include <list>
#include "Header.h"
using namespace std;

// 4.3 List of Depths:
// Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth
// (e.g., if you have a tree with depth D, you'll have D linked lists).


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
    Tree tree;
    tree.makeSampleBST(10);
    tree.printTree(tree.root);
    
    vector<list<Node *>> lists;
    createLevelLinkedLists(tree.root, lists, 0);
    printLinkedLists(lists);
}
