#include <iostream>
using namespace std;

// 2.7 Intersection:
// Given two (singly) linked lists, determine if the two lists intersect.
// Return the intersecting node.
// Note that the intersection is defined based on reference, not value.
// That is, if the Kth node of the first linked list is the exact same node (by reference) as
// the Jth node of the second linked list, then they are intersecting.

struct Node
{
    int data;
    Node * next;
    
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

void insertAtHead(Node * & head, int data)
{
    Node * newNode = new Node(data);
    newNode->next = head;
    
    head = newNode;
}

int getLenght(Node * head)
{
    int cnt = 0;
    while(head != nullptr)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void printList(Node * head)
{
    while(head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


Node * getIntersection(Node * list1, Node * list2)
{
    int len1 = getLenght(list1);
    int len2 = getLenght(list2);
    
    Node * shorter = (len1 < len2) ? list1 : list2;
    Node * longer = (len1 < len2) ? list2 : list1;
    
    for (int i = 0; i < abs(len1 - len2); i++)
        longer = longer->next;
    
    while(shorter != nullptr && longer != nullptr)
    {
        if (shorter == longer) return shorter;

        shorter = shorter->next;
        longer = longer->next;
    }
    
    return nullptr;
}

void printResult(Node * node)
{
    if (node == nullptr) cout << "There's no intersection" << endl;
    else                 cout << "The intersection is " << node->data << endl;
}


int main()
{
    Node * list1 = new Node(3);
    list1->next = new Node(6);
    list1->next->next = new Node(9);
    list1->next->next->next = new Node(12);
    list1->next->next->next->next = new Node(15);
    list1->next->next->next->next->next = new Node(18);

    Node * list2 = new Node(7);
    list2->next = new Node(10);
    list2->next->next = list1->next->next->next;

    printList(list1);
    printList(list2);
    
    printResult(getIntersection(list1, list2));
}
