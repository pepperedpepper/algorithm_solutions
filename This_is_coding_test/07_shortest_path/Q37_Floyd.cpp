#include <iostream>
using namespace std;

// 1 ~ n의 도시가 있을 때 모든 도시의 쌍에 대해 최소 비용을 계산하시오.
// 시작도시와 도착도시가 같은 경우는 없다.
// 시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.

// 입력:  5        -> 도시의 개수 n (<= 100)
//       14       -> 버스의 개수 m
//       1 2 2    -> 시작도시 a, 도착도시 b, 비용 c
//       1 3 3
//       1 4 1
//       1 5 10
//       2 4 2
//       3 4 1
//       3 5 1
//       4 5 3
//       3 5 10
//       3 1 8
//       1 4 2
//       5 1 7
//       3 4 2
//       5 2 4
// 출력:  0 2 3 1 4      -> 각 도시로 가는 최소 비용. 갈 수 없으면 0
//       12 0 15 2 5
//       8 5 0 1 1
//       10 7 13 0 3
//       7 4 10 6 0

const int INF = 1e9;
const int CITY_COUNT_MAX = 101;
int graph[CITY_COUNT_MAX][CITY_COUNT_MAX];
int cityNum, busNum, from, to, cost;

void Floyd()
{
    for (int k = 1; k <= cityNum; k++)
    {
        for (int a = 1; a <= cityNum; a++)
        {
            if (graph[a][k] == INF) continue;
            
            for (int b = 1; b <= cityNum; b++)
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
        }
    }
}

int main()
{
    cin >> cityNum >> busNum;
    
    for (int i = 1; i <= cityNum; i++)
        fill(graph[i], graph[i] + cityNum + 1, INF);
    
    for (int i = 1; i <= cityNum; i++)
        graph[i][i] = 0;
        
    for (int i = 0; i < busNum; i++)
    {
        cin >> from >> to >> cost;
        graph[from][to] = min(graph[from][to], cost);
    }
    
    Floyd();
    
    for (int i = 1; i <= cityNum; i++)
    {
        for (int j = 1; j <= cityNum; j++)
        {
            if (graph[i][j] == INF) cout << 0 << ' ';
            else                    cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
}
