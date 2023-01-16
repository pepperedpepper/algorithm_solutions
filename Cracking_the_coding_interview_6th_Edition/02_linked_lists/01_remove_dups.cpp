#include <iostream>
#include <unordered_map>
using namespace std;

// 2.1 Remove Dups:
// Write code to remove duplicates from an unsorted linked list.
// How would you solve this problem if a temporary buffer is not allowed?

struct Node
{
    int data;
    Node * next;
};

Node * insert(Node * prev, int newData)
{
    Node * newNode = new Node();
    newNode->data = newData;
    prev->next = newNode;
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


void removeDupsWithHashTable(Node * head)
{
    unordered_map<int, int> nodeMap;
    
    nodeMap[head->data] = 1;
    
    Node * prev = head;
    Node * target = head->next;
    while(target != nullptr)
    {
        while(target != nullptr && nodeMap.find(target->data) != nodeMap.end())
        {
            Node * next = target->next;
            delete target;
            target = next;
        }
        
        // 연결
        prev->next = target;
        
        // target은 새로운 값
        if (target != nullptr)
        {
            nodeMap[target->data] = 1;
            prev = target;
            target = target->next;
        }
    }
}


void removeDups(Node * head)
{
    Node * target = head;
    while(target != nullptr)
    {
        Node * prevChecker = target;
        while(prevChecker->next != nullptr)
        {
            if (prevChecker->next->data == target->data)
            {
                Node * next = prevChecker->next->next;
                delete prevChecker->next;
                prevChecker->next = next;
            }
            else
            {
                prevChecker = prevChecker->next;
            }
        }
        
        target = target->next;
    }
}


int main()
{
    Node * head = new Node();
    Node * next = insert(head, 1);
    next = insert(next, 2);
    next = insert(next, 2);
    next = insert(next, 9);
    next = insert(next, 2);
    next = insert(next, 4);
    next = insert(next, 2);
    
    cout << "Before : " << endl;
    print(head);
    
    cout << "After : " << endl;
    removeDupsWithHashTable(head);
    print(head);
}
