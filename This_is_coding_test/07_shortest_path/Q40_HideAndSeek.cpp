#include <iostream>
#include <queue>
using namespace std;

// 숨바꼭질 중이다. 숨을 곳은 1 ~ n번까지의 헛간이다.
// 술래는 항상 1번 헛간에서 출발한다.
// 전체 맵에는 총 m개의 양방향 통로가 존재한다.
// 1번 헛간에서 최단 거리가 가장 긴 헛간이 가장 안전하겠다.

// 입력:  6 7   -> 헛간 개수 n, 통로 개수 m
//       3 6   -> 헛간 a, 헛간 b를 잇는 양방향 통로가 있다.
//       4 3
//       3 2
//       1 3
//       1 2
//       2 4
//       5 2
// 출력:  4 2 3  -> 숨을 헛간 번호, 숨을 헛간까지의 거리, 같은 거리의 헛간 개수

const int INF = 1e9;
const int PLACE_COUNT_MAX = 20001;
const int START_POS = 1;

vector<int> graph[PLACE_COUNT_MAX];
int costs[PLACE_COUNT_MAX];

int placeCount, wayCount, a, b;
int resultPlace = 0, resultDistance = 0, resultSame = 0;

void Djikstra()
{
    for (int i = 1; i <= placeCount; i++)
        costs[i] = INF;
    
    priority_queue<pair<int, int>> pq;
    pq.push({0, START_POS});
    costs[START_POS] = 0;
    
    while(pq.empty() == false)
    {
        int from = pq.top().second;
        int fromCost = -pq.top().first;
        pq.pop();
        
        if (resultDistance == fromCost)
        {
            resultPlace = min(resultPlace, from);
            resultSame++;
        }
        else if (resultDistance < fromCost)
        {
            resultPlace = from;
            resultSame = 1;
            resultDistance = fromCost;
        }
        
        if (costs[from] < fromCost) continue;
        
        for (int i = 0; i < graph[from].size(); i++)
        {
            int to = graph[from][i];
            int toCost = fromCost + 1;
            
            if (costs[to] <= toCost) continue;
            
            costs[to] = toCost;
            pq.push({-toCost, to});
        }
    }
}

int main()
{
    cin >> placeCount >> wayCount;
    
    for (int i = 0; i < wayCount; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    Djikstra();
    
    cout << resultPlace << ' ' << resultDistance << ' ' << resultSame << '\n';
}
