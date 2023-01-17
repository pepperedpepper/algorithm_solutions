#include <iostream>
#include <stack>
using namespace std;

// 3.5 Sort Stack:
// Write a program to sort a stack such that the smallest items are on the top.
// You can use an additional temporary stack, but you may not copy the elements into any other data structure
// (such as an array).
// The stack supports the following operations: push, pop, peek, and is Empty.


class SortedStack
{
private:
    stack<int> s;
    
public:
    void push(int data)
    {
        stack<int> temp;
        while(s.empty() == false && s.top() < data)
        {
            temp.push(s.top());
            s.pop();
        }
        
        s.push(data);
        
        while(temp.empty() == false)
        {
            s.push(temp.top());
            temp.pop();
        }

        cout << data << " is pushed " << endl;
    }
    
    void pop()
    {
        if (isEmpty() == true)
        {
            cout << "stack is empty" << endl;
            return;
        }
        
        cout << peek() << " is popped " << endl;
        s.pop();
    }
    
    int peek()
    {
        return s.top();
    }
    
    bool isEmpty()
    {
        return s.empty();
    }
};


int main()
{
    SortedStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(5);
    s.push(4);
    
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
}
