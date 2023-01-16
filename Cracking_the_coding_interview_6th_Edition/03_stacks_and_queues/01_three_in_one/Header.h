

enum StackType
{
    One, Two, Three, Max
};

class ThreeInOne
{
private:
    int stackSize;
    int * curSize;
    int * ptr;
    
public:
    ThreeInOne(int stackSize);
    virtual ~ThreeInOne();
    
    void push(StackType type, int data);
    int pop(StackType type);
    int top(StackType type);
    bool isEmpty(StackType type);
    bool isFull(StackType type);
    int indexOfTop(StackType type);
};
