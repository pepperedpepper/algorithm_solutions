#include <iostream>
#include <stack>
using namespace std;

// 3.4 Queue via Stacks:
// Implement a MyQueue class which implements a queue using two stacks.


class MyQueue
{
private:
    stack<int> s1;
    stack<int> s2;
    
public:
    void enqueue(int data)
    {
        s1.push(data);
        
        cout << s1.top() << " is enqueued" << endl;
    }
    
    void dequeue()
    {
        if (s1.empty() == true && s2.empty() == true)
        {
            cout << "queue is empty" << endl;
            return;
        }
        
        while(s1.empty() == false)
        {
            s2.push(s1.top());
            s1.pop();
        }
        
        cout << s2.top() << " is dequeued" << endl;
        s2.pop();
    }
};


int main()
{
    MyQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
}
