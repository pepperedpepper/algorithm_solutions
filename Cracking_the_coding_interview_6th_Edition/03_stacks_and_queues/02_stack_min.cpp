#include <iostream>
#include <stack>
using namespace std;

// 3.2 Stack Min:
// How would you design a stack which, in addition to push and pop,
// has a function min which returns the minimum eiement?
// Push, pop and min should all operate in O(1) time.

class StackWithMin
{
private:
    stack<int> s;
    stack<int> m;
    
public:
    void push(int data)
    {
        s.push(data);
        
        int min = (m.empty() == true || data < m.top()) ? data : m.top();
        m.push(min);
    }
    
    void pop()
    {
        cout << "pop : " << s.top() << " , min : " << m.top() << endl;
        s.pop();
        m.pop();
    }
};


int main()
{
    StackWithMin s;
    s.push(1);
    s.push(3);
    s.push(0);
    s.push(2);
    
    s.pop();
    s.pop();
    s.pop();
    s.pop();
}
