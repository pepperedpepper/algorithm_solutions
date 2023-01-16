#include <iostream>
#include <stack>
using namespace std;

// 2.6 Palindrome:
// Implement a function to check if a linked list is a palindrome.


struct Node
{
    char data;
    Node * next;
    
    Node(char data)
    {
        this->data = data;
        next = nullptr;
    }
};

void insertAtHead(Node * & head, char data)
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


bool iterative(Node * head)
{
    if (head == nullptr || head->next == nullptr) return true;
    
    Node * front = head;
    Node * back = head;
    
    stack<Node *> nodeStack;
    
    while(front != nullptr && front->next != nullptr && back != nullptr)
    {
        nodeStack.push(back);
        
        front = front->next->next;
        back = back->next;
    }
    
    if (front != nullptr && front->next == nullptr)
        back = back->next;
    
    while(nodeStack.empty() == false && back != nullptr)
    {
        Node * cur = nodeStack.top();
        nodeStack.pop();
        
        if (cur->data != back->data) return false;
        back = back->next;
    }
    
    return true;
}


bool recursiveHelper(Node * & head, Node * cur, int count, int * max)
{
    if (cur == nullptr)
    {
        *max = count - 1;
        return true;
    }
    
    bool isSame = recursiveHelper(head, cur->next, count + 1, max);
    if (isSame == false) return false;
    if (count <= *max / 2 + 1) return isSame;
    
    isSame = (head->data == cur->data);
    
    head = head->next;
    return isSame;
}

bool recursive(Node * head)
{
    int max = 0;
    return recursiveHelper(head, head, 1, &max);
}


int main()
{
    Node * head = nullptr;
    insertAtHead(head, 'a');
    insertAtHead(head, 'b');
    insertAtHead(head, 'b');
    insertAtHead(head, 'a');

    cout << "string: ";
    printList(head);
    cout << (iterative(head) == true ? "TRUE" : "FALSE") << endl;
    cout << (recursive(head) == true ? "TRUE" : "FALSE") << endl;
}
