#include <iostream>
using namespace std;

// 1 ~ n의 여행지가 있다. 도로가 연결되어 있다면 양방향으로 이동이 가능하다.
// 여행 계획이 가능한지 여부를 출력하라.

// 입력:  5 4        -> 여행지의 수 n, 여행 계획에 있는 여행지의 수  m
//       0 1 0 1 1  -> 두 여행지가 서로 연결되어 있는지 (0-X, 1-O)
//       1 0 1 1 0
//       0 1 0 0 0
//       1 1 0 0 0
//       1 0 0 0 0
//       2 3 4 3    -> 여행 계획에 있는 여행지 순서
// 출력:  YES        -> 여행 가능 여부

const int PLACE_COUNT_MAX = 501;
int placeCount, planCount;
int graph[PLACE_COUNT_MAX][PLACE_COUNT_MAX];
int plans[PLACE_COUNT_MAX];
int parent[PLACE_COUNT_MAX];

int FindParent(int x)
{
    if (parent[x] == x)
        return x;
    
    return parent[x] = FindParent(parent[x]);
}

void Union(int a, int b)
{
    a = parent[a];
    b = parent[b];
    
    if (a < b) b = parent[a];
    else       a = parent[b];
}

int main()
{
    cin >> placeCount >> planCount;
    
    for (int i = 1; i <= placeCount; i++)
        parent[i] = i;
    
    for (int i = 1; i <= placeCount; i++)
    {
        for (int j = 1; j <= placeCount; j++)
        {
            cin >> graph[i][j];
            
            if (graph[i][j] == 1 && FindParent(i) != FindParent(j))
                Union(i, j);
        }
    }
    
    int goalParent = plans[0];
    for (int i = 1; i < planCount; i++)
    {
        if (plans[i] != goalParent)
        {
            cout << "NO" << '\n';
            return 0;
        }
    }
    
    cout << "YES" << '\n';
}
