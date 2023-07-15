#include <iostream>
using namespace std;

// 1 ~ g번까지의 탑승구가 있다.
// 비행기는 다른 비행기가 도킹하지 않은 탑승구만 도킹할 수 있는데,
// 만약 어떠한 탑승구에도 도킹할 수 없는 비행기가 나오면 공항의 운행을 중지한다.
// 최대한 도킹할 수 있는 비행기의 수는 몇인가?

// 입력:   4  -> 탑승구의 수 g
//        3  -> 비행기의 수 p
//        4  -> 비행기가 도킹할 수 있는 탑승구의 정보. 1 ~ 4번 탑승구까지 도킹할 수 있다는 뜻이다.
//        1
//        1

// 출력:   2

const int GATE_COUNT_MAX = 100001;
int gateParent[GATE_COUNT_MAX];
int gateCount, airplaneCount, curMaxGate;

int FindParent(int x)
{
    if (gateParent[x] == x) return x;
    
    return gateParent[x] = FindParent(gateParent[x]);
}

void Union(int a, int b)
{
    a = gateParent[a];
    b = gateParent[b];
    
    if (a < b) gateParent[b] = a;
    else       gateParent[a] = b;
}

int main()
{
    cin >> gateCount >> airplaneCount;
    
    for (int i = 1; i <= gateCount; i++)
        gateParent[i] = i;
    
    int result = 0;
    for (int i = 0; i < airplaneCount; i++)
    {
        cin >> curMaxGate;
        
        int curParentGate = FindParent(curMaxGate);
        if (curParentGate == 0) break;
        
        Union(curParentGate - 1, curParentGate);
        result++;
    }
    
    cout << result << '\n';
}
