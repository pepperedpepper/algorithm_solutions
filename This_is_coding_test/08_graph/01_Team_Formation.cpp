#include <iostream>
using namespace std;

// 각기 서로 다른 팀 소속인 0번부터 n번까지의 학생이 있다.
// 선생님이 아래 연산을 총 m번 수행할 때, (1) 같은 팀 여부 확인 연산 결과를 출력하라.

// 연산 종류
//    0. 팀 합치기
//    1. 같은 팀 여부 확인

// 입력:    7 8    -> 최대 학생번호 n, 연산 개수 m
//         0 1 3  -> 연산번호, 학생번호 a, 학생번호 b
//         1 1 7
//         0 7 6
//         1 7 1
//         0 3 7
//         0 4 2
//         0 1 1
//         1 1 1
// 출력:    NO    -> 같은팀 여부
//         NO
//         YES

const int TEAM_COUNT_MAX = 100001;
int parent[TEAM_COUNT_MAX];
int lastTeamNumber, operationCount, inputOp, a, b;

void UnionTeam(int a, int b)
{
    a = parent[a];
    b = parent[b];
    
    if (a < b) parent[a] = b;
    else       parent[b] = a;
}

int FindParent(int x)
{
    if (x == parent[x]) return x;
    
    return parent[x] = FindParent(parent[x]);
}


int main()
{
    cin >> lastTeamNumber >> operationCount;
    
    for (int i = 0; i <= lastTeamNumber; i++)
        parent[i] = i;
    
    for (int i = 0; i < operationCount; i++)
    {
        cin >> inputOp >> a >> b;
        
        if (0 == inputOp)
        {
            UnionTeam(a, b);
            continue;
        }
        
        if (FindParent(a) == FindParent(b)) cout << "YES" << '\n';
        else                                cout << "NO" << '\n';
    }
}
