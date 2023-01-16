#include <iostream>
using namespace std;

// 2.2 Return Kth to Last:
// Implement an algorithm to find the Kth to last element of a singly linked list.


struct Node
{
    int data;
    Node * next;
};

Node * insert(Node * head, int newData)
{
    Node * newNode = new Node();
    newNode->data= newData;
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

void printResult(Node * node)
{
    if (node == nullptr)
        cout << "NULL" << endl;
    else
        cout << node->data << endl;
}


Node * recursiveHelper(Node * head, int k, int & cnt)
{
    if (head == nullptr) return nullptr;
    
    Node * result = recursiveHelper(head->next, k, cnt);
    cnt += 1;
    
    if (cnt == k) return head;
    return result;
}

Node * recursive(Node * head, int k)
{
    int cnt = 0;
    return recursiveHelper(head, k, cnt);
}


// two pointers
Node * iterative(Node * head, int k)
{
    Node * p1 = head;
    Node * p2 = head;
    
    // p1는 p2로부터 K만큼 앞에 있다.
    for (int i = 0; i < k; i++)
    {
        if (p1 == nullptr) return nullptr;
        p1 = p1->next;
    }
    
    while(p1 != nullptr)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return p2;
}


int main()
{
    Node * head = new Node();
    Node * next = head;
    for (int i = 1; i <= 10; i++)
        next = insert(next, i);
    
    cout << "Linked list" << endl;
    print(head);
    
    int k = 3;
    cout << "Find " << k << "th to last node with recursive: " << endl;
    printResult(recursive(head, k));
    
    k = 5;
    cout << "Find " << k << "th to last node with iterative: " << endl;
    printResult(iterative(head, k));
}
