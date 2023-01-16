#include <iostream>
using namespace std;
// 2.5 Sum Lists:
// You have two numbers represented by a linked list, where each node contains a single digit.
// The digits are stored in reverse order, such that the Vs digit is at the head of the list.
// Write a function that adds the two numbers and returns the sum as a linked list.


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

void printList(Node * head)
{
    while(head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


Node * sumWithReversedList(Node * list1, Node * list2, int carry = 0)
{
    if (list1 == nullptr && list2 == nullptr && carry == 0) return nullptr;
    
    Node * result;
    
    int cur = carry;
    if (list1 != nullptr)
    {
        cur += list1->data;
        list1 = list1->next;
    }
    if (list2 != nullptr)
    {
        cur += list2->data;
        list2 = list2->next;
    }
    
    result = sumWithReversedList(list1, list2, cur >= 10 ? 1 : 0);
    
    insertAtHead(result, cur % 10);
    
    return result;
}


// Suppose the digits are stored in forward order. Repeat the above problem.
void inputZeros(Node * & list1, Node * & list2)
{
    int cnt = 0;
    Node * cur = list1;
    while(cur != nullptr)
    {
        cnt++;
        cur = cur->next;
    }
    
    cur = list2;
    while(cur != nullptr)
    {
        cnt--;
        cur = cur->next;
    }
    
    bool isList1 = (cnt < 0);
    cnt = (cnt < 0) ? -cnt : cnt;
    
    for (int i = 0; i < cnt; i++)
    {
        if (isList1) insertAtHead(list1, 0);
        else         insertAtHead(list2, 0);
    }
}

Node * sumWithForwardListHelper(Node * list1, Node * list2, int * carry)
{
    if (list1 == nullptr || list2 == nullptr) return nullptr;
    
    Node * result;
    
    int cur = list1->data + list2->data;

    result = sumWithForwardListHelper(list1->next, list2->next, carry);
    
    cur += *carry;
    insertAtHead(result, cur % 10);
    *carry = (cur >= 10) ? 1 : 0;
    
    return result;
}

Node * sumWithForwardList(Node * list1, Node * list2)
{
    inputZeros(list1, list2);
    int carry = 0;
    return sumWithForwardListHelper(list1, list2, &carry);
}


int main()
{
    // 1 -> 6
    Node * list1 = nullptr;
    insertAtHead(list1, 6);
    insertAtHead(list1, 1);
    cout << "List1: ";
    printList(list1);

    // 5 -> 9 -> 2
    Node * list2 = nullptr;
    insertAtHead(list2, 2);
    insertAtHead(list2, 9);
    insertAtHead(list2, 5);
    cout << "List2: ";
    printList(list2);
    
    //    61   1 -> 6
    // + 295   5 -> 9 -> 2
    // = 356   6 -> 5 -> 3
    Node * sum = sumWithReversedList(list1, list2);
    cout << "Sum with reversed list: ";
    printList(sum);
    
    //    16   1 -> 6
    // + 592   5 -> 9 -> 2
    // = 608   6 -> 0 -> 8
    sum = sumWithForwardList(list1, list2);
    cout << "Sum with forward list:  ";
    printList(sum);
    
}
