#include <iostream>
#include <queue>
using namespace std;

// 도시 c에서 최대한 많은 도시로 메시지를 보내고자 한다.
// 메시지를 받는 도시는 몇 개이며, 총 걸리는 시간은 얼마인가?

// 입력:   3 2 1  -> 도시의 개수 n, 통로의 개수 m, 메시지를 보내고자 하는 도시 c
//        1 2 4  -> 도시 x에서 도시 y까지 가는 비용은 z
//        1 3 2
// 출력:   2 4    -> 도시 c에서 보낸 메시지를 받는 도시의 총 개수, 총 걸리는 시간

const int INF = 1e9;
const int CITY_COUNT_MAX = 30001;
vector<pair<int, int>> graph[CITY_COUNT_MAX]; // [from] = {to, cost};
int costs[CITY_COUNT_MAX];

int cityCount, edgeCount, startCity;
int from, to, cost;
int resultCost = 0, resultCityCount = 0;

void Djistra()
{
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, startCity });
    costs[startCity] = 0;
    
    while(pq.empty() == false)
    {
        int from = pq.top().second;
        int fromCost = -pq.top().first;
        pq.pop();
        
        for (int i = 0; i < graph[from].size(); i++)
        {
            int to = graph[from][i].first;
            int toCost = graph[from][i].second + fromCost;
            
            if (costs[to] <= toCost) continue;
            
            costs[to] = toCost;
            pq.push({ -toCost, to });
        }
    }
}

int main()
{
    cin >> cityCount >> edgeCount >> startCity;
    
    for (int i = 0; i < edgeCount; i++)
    {
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
    }
    
    fill(costs, costs + cityCount + 1, INF);
    
    Djistra();
    
    for (int i = 1; i <= cityCount; i++)
    {
        if (costs[i] != INF)
        {
            resultCityCount++;
            resultCost = max(resultCost, costs[i]);
        }
    }
    
    cout << resultCityCount - 1 << ' ' << resultCost << '\n';
}
