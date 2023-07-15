#include <iostream>
#include <queue>
using namespace std;

// n X n의 공간에서 각각 칸을 지나는 비용이 존재할 때,
// (0, 0)에서 (n-1, n-1)위치로 이동하는 최소 비용을 출력하라.
// 이동은 상, 하, 좌, 우로 가능하다.

// 입력:    3        -> 테스트 케이스 수
//         3        -> 맵 크기 n
//         5 5 4    -> 맵 정보
//         3 9 1
//         3 2 7
//         5
//         3 7 2 0 1
//         2 8 0 9 1
//         1 2 1 8 1
//         9 8 9 2 0
//         3 6 5 1 5
//         7
//         9 0 5 1 1 5 3
//         4 1 2 1 6 5 3
//         0 7 6 1 6 8 5
//         1 1 7 8 3 2 3
//         9 4 0 7 6 4 1
//         5 8 3 2 4 8 3
//         7 4 8 4 8 3 4
// 출력:    20
//         19
//         36

const int INF = 1e9;
const int MAP_SIZE_MAX = 125;
const int STEP_MAX = 4;
const pair<int, int> STEPS[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int map[MAP_SIZE_MAX][MAP_SIZE_MAX];
int costs[MAP_SIZE_MAX][MAP_SIZE_MAX];
int caseCount, mapSize;


void Djistra()
{
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({ -map[0][0], {0, 0} });
    costs[0][0] = map[0][0];
    
    while(pq.empty() == false)
    {
        int fromX = pq.top().second.first;
        int fromY = pq.top().second.second;
        int fromCost = -pq.top().first;
        pq.pop();
        
        if (costs[fromY][fromX] < fromCost) continue;
        
        for (int i = 0; i < STEP_MAX; i++)
        {
            int toX = fromX + STEPS[i].first;
            int toY = fromY + STEPS[i].second;

            if (toX < 0 || toY < 0 || mapSize <= toX || mapSize <= toY) continue;
            
            int toCost = fromCost + map[toY][toX];
            if (costs[toY][toX] <= toCost) continue;
            
            costs[toY][toX] = toCost;
            pq.push({ -toCost, {toX, toY} });
        }
    }
}

int main()
{
    cin >> caseCount;
    
    for (int c = 0; c < caseCount; c++)
    {
        cin >> mapSize;
        
        for (int i = 0; i < mapSize; i++)
            fill(costs[i], costs[i] + mapSize, INF);
        
        for (int i = 0; i < mapSize; i++)
            for (int j = 0; j < mapSize; j++)
                cin >> map[i][j];
        
        Djistra();
        
        cout << costs[mapSize - 1][mapSize - 1] << '\n';
    }
}
