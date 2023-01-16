#include <iostream>
using namespace std;

// 2.8 Loop Detection:
// Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.

// Circular linked list:
//   A (corrupt) linked list in which a node's next pointer points to an earlier node,
//   so as to make a loop in the linked list.


struct Node
{
    int data;
    Node * next;
    
    Node(int data)
    {
        this->data = data;
    }
};

void insert(Node * & head, int data)
{
    Node * newNode = new Node(data);
    
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    
    Node * cur = head;
    while(cur->next != nullptr)
        cur = cur->next;
    
    cur->next = newNode;
}

void print(Node * head)
{
    while(head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void printResult(Node * node)
{
    if (node == nullptr) cout << "No loop" << endl;
    else                 cout << "Loop node : " << node->data << endl;
}


Node * detectLoop(Node * head)
{
    if (head == nullptr) return nullptr;
    
    Node * fast = head;
    Node * slow = head;
    
    // 루프가 있다면, 2칸씩 이동하는 노드와 1칸씩 이동하는 노드는 반드시 만난다.
    
    // 1칸씩 이동하는 노드가 K번 이동해서 루프 시작점에 도착한다면,
    // 2칸씩 이동하는 노드는 K + K만큼 이동했을테니, 루프 시작점에서 K번째 떨어진 곳에 위치하겠다.
    
    // 두 노드가 K만큼 떨어진 이 상태에서 시작해서, 루프 안에서 서로 만나려면 얼마나 걸릴까?
    // 1칸씩 이동하는 노드는 루프 시작점에 있으므로,
    // 2칸씩 이동하는 노드가 (LoopSize - K) 만큼 뒤쳐진 상태가 된다.
    // 2칸씩 이동하는 노드는 1칸씩 이동하는 노드를 1번 이동할 때마다 노드 1개만큼 따라잡을 수 있다.
    // 따라서 (LoopSize - K)번 각자 이동하면 결국 만나게 된다.
    
    // 1번 이동하는 노드는 루프 시작점에서 (LoopSize - K)번 이동한 상태이다.
    // 여기서 (만난 위치에서) K번만 한칸씩 앞으로 더 가면 루프 시작점이 되겠다.
    // 이 K는 처음에 이야기 했듯이 1칸씩 이동하는 노드가 루프 시작점에 도달하기위해 필요했던 이동횟수와 같다.
    // 따라서 head부터 시작해서 1칸씩 이동하는 노드와 만난 위치에서 1칸씩 이동하는 노드가 만나는 위치가
    // 바로 루프 시작점이 되겠다.
    
    while(slow != nullptr && fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        
        if (slow == fast) break;
    }
    
    if (slow == nullptr || fast == nullptr) return nullptr;
    
    slow = head;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
}


int main()
{
    Node * head = nullptr;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    head->next->next->next->next->next = head->next->next; // 5 -> 3
    
    printResult(detectLoop(head));
}
