#include <iostream>
#include "Header.h"
using namespace std;

// 3.1 Three in One:
// Describe how you could use a single array to implement three stacks.


int main()
{
    ThreeInOne s(3);
    
    s.push(One, 1);
    s.push(One, 2);
    s.push(One, 3);
    s.push(Two, 4);
    s.push(Two, 5);
    s.push(Three, 6);
    
    s.pop(One);
    s.pop(One);
    s.pop(One);
    s.pop(Two);
    s.pop(Two);
    s.pop(Three);
}
