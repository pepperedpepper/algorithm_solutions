#include <iostream>
#include <random>
using namespace std;

// 2.4 Partition:
// Write code to partition a linked list around a value x,
// such that all nodes less than x
// come before all nodes greater than or equal to x.
// If x is contained within the list,
// the values of x only need to be after the elements less than x (see below).
// The partition element x can appear anywhere in the "right partition";
// it does not need to appear between the left and right partitions.

struct Node
{
    int data;
    Node * next;
    
    Node(int input)
    {
        data = input;
        next = nullptr;
    }
};

Node * insert(Node * head, int newData)
{
    Node * newNode = new Node(newData);
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

int getRandomNumber(int min, int max)
{
    // 시드값을 얻기 위한 random_device 생성.
    std::random_device rd;

    // random_device 를 통해 난수 생성 엔진을 초기화 한다.
    std::mt19937 mt(rd());

    // 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
    std::uniform_int_distribution<int> distribution(min, max);
    
    return distribution(mt);
}


Node * makePartition(Node * head, int x)
{
    Node * headOfBeforeX = nullptr;
    Node * beforeX = nullptr;
    Node * headOfAfterX = nullptr;
    Node * afterX = nullptr;
    
    Node * cur = head;
    while(cur != nullptr)
    {
        Node * next = cur->next;
        
        if (cur->data < x)
        {
            if (beforeX == nullptr)
                headOfBeforeX = cur;
            else
                beforeX->next = cur;
            beforeX = cur;
        }
        else
        {
            if (afterX == nullptr)
                headOfAfterX = cur;
            else
                afterX->next = cur;
            afterX = cur;
        }
        
        cur = next;
    }
    
    if (beforeX == nullptr || afterX == nullptr) return head;

    beforeX->next = headOfAfterX;
    afterX->next = nullptr;
    
    return headOfBeforeX;
}


int main()
{
    Node * head = new Node(0);
    Node * next = head;
    for ( int i = 1; i < 10; ++i )
        next = insert(next, getRandomNumber(0, 10));
    
    cout << "Before : " << endl;
    print(head);
    
    cout << "After : " << endl;
    head = makePartition(head, 5);
    print(head);
}
