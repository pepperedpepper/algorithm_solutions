#include <iostream>
#include <stack>
using namespace std;


// 3.3 Stack of Plates:
// Imagine a (literal) stack of plates.
// If the stack gets too high, it might topple.
// Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold.
// Implement a data structure SetOfStacks that mimics this.
// SetOfStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity.
// SetOfStacks .push() and SetOfStacks .pop() should behave identically to a single stack
// (that is, pop() should return the same values as it would if there were just a single stack).

// FOLLOW UP
// Implement a function popAt( int index ) which performs a pop operation on a specific sub-stack.




class StackOfPlates
{
private:
    const int STACK_NUM = 10;
    int capacity;
    
    stack<int> * stacks;
    int idx;

public:
    StackOfPlates(int size)
    {
        capacity = size;
        stacks = new stack<int>[STACK_NUM];
        idx = 0;
    }
    
    ~StackOfPlates()
    {
        delete [] stacks;
    }
    
    void push(int data)
    {
        if (capacity <= stacks[idx].size()) idx++;
        if (STACK_NUM <= idx)
        {
            cout << "stack is full" << endl;
            return;
        }
        
        stacks[idx].push(data);

        cout << stacks[idx].top() << " is pushed in " << idx << endl;
    }
    
    void pop()
    {
        if (stacks[idx].size() <= 0) idx--;
        if (idx < 0)
        {
            idx = 0;
            cout << "stack is empty" << endl;
            return;
        }
        
        cout << stacks[idx].top() << " is popped from " << idx << endl;
        
        stacks[idx].pop();
    }
    
    void popAt(int index)
    {
        if (index < 0 || index >= STACK_NUM || index > idx)
            cout << "not valid idx" << endl;

        cout << stacks[index].top() << " is popped from " << index << endl;
        
        stacks[index].pop();
    }
};



int main()
{
    StackOfPlates s(3);
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11);
    s.push(12);
    
    s.pop();
    s.popAt(2);
    s.pop();
}
