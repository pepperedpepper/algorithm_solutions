#include <iostream>
using namespace std;

// 2.3 Delete Middle Node:
// Implement an algorithm to delete a node in the middle
// (i.e., any node but the first and last node, not necessarily the exact middle)
// of a singly linked list, given only access to that node.

struct Node
{
    char data;
    Node * next;
    
    Node(char input)
    {
        data = input;
        next = nullptr;
    }
};

Node * insert(Node * head, char newData)
{
    Node * newNode = new Node(newData);
    head->next = newNode;
    return newNode;
}

void print(Node * head)
{
    while(head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}



void deleteNode(Node * target)
{
    if (target == nullptr || target->next == nullptr) return;
    
    Node * next = target->next;
    target->data = next->data;
    target->next = next->next;
    
    delete next;
}


int main()
{
    Node * head = new Node('a');
    head->next = new Node('b');
    head->next->next = new Node('c');
    head->next->next->next = new Node('d');
    head->next->next->next->next = new Node('e');
    
    cout << "Before : " << endl;
    print(head);
    
    cout << "After : " << endl;
    deleteNode(head->next->next);
    print(head);
}
