#include <iostream>
#include "Header.h"
using namespace std;


ThreeInOne::ThreeInOne(int stackSize)
{
    this->stackSize = stackSize;

    ptr = new int [stackSize * Max];
    curSize = new int [Max];
}

ThreeInOne::~ThreeInOne()
{
    delete [] ptr;
    delete [] curSize;
}

void ThreeInOne::push(StackType type, int data)
{
    if (Max <= type)
    {
        cout << "It's not a right type" << endl;
        return;
    }
    if (isFull(type))
    {
        cout << "It's full" << endl;
        return;
    }
    
    curSize[type]++;
    
    ptr[indexOfTop(type)] = data;

    cout << type << " push : " << top(type) << endl;
}

int ThreeInOne::pop(StackType type)
{
    if (Max <= type)
    {
        cout << "It's not a right type" << endl;
        return -1;
    }
    if (isEmpty(type))
    {
        cout << "It's empty" << endl;
        return -1;
    }
    
    cout << type << " pop : " << top(type) << endl;
    
    int result = ptr[indexOfTop(type)];
    
    curSize[type]--;
    
    return result;
}

int ThreeInOne::top(StackType type)
{
    if (Max <= type)
    {
        cout << "It's not a right type" << endl;
        return -1;
    }
    if (isEmpty(type))
    {
        cout << "It's empty" << endl;
        return -1;
    }
    
    int result = ptr[indexOfTop(type)];
    return result;
}

bool ThreeInOne::isEmpty(StackType type)
{
    return curSize[type] <= 0;
}

bool ThreeInOne::isFull(StackType type)
{
    return stackSize <= curSize[type];
}

int ThreeInOne::indexOfTop(StackType type)
{
    return (curSize[type] - 1) * Max + type;
}

