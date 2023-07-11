#include <iostream>
using namespace std;

// 방문 판매원이 1번 회사에서 출발해서 k번을 거쳐서 x번으로 가는 데 드는 최소 시간은?
// 양방향 이동 가능하며, 연결되어 있다면 1만큼 걸린다.

// 입력:    5 7    -> 전체 회사의 개수 n, 전체 경로의 개수 m
//         1 2    -> 연결된 두 회사의 번호들
//         1 3
//         1 4
//         2 4
//         3 4
//         3 5
//         4 5
//         4 5    -> 도착회사 x, 중간지점 k
// 출력:    3      -> 최소 이동 시간

// 입력:    4 2
//         1 3
//         2 4
//         3 4
// 출력:    -1

const int INF = 1e9;
const int START_POS = 1;
const int POS_COUNT_MAX = 101;

int graph[POS_COUNT_MAX][POS_COUNT_MAX];

int posCount, edgeCount, midPos, finishPos;
int a, b;

void FindMinCosts()
{
    for (int k = 1; k < posCount + 1; k++)
        for (int a = 1; a < posCount + 1; a++)
            for (int b = 1; b < posCount + 1; b++)
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
}

int main()
{
    cin >> posCount >> edgeCount;
    
    for (int i = 1; i < posCount + 1; i++)
        fill(graph[i], graph[i] + posCount + 1, INF);
    
    for (int i = 1; i < posCount + 1; i++)
        graph[i][i] = 0;
    
    for (int i = 0; i < edgeCount; i++)
    {
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    
    cin >> finishPos >> midPos;
    
    FindMinCosts();
    
    int result = graph[START_POS][midPos] + graph[midPos][finishPos];
    
    if (INF <= result) cout << -1 << '\n';
    else               cout << result << '\n';
}
