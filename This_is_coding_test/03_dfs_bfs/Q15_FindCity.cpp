#include <iostream>
#include <queue>
using namespace std;

// 1 ~ n번 도시에는 m개의 단방향 도로가 있다. 모든 도로의 거리는 1이다.
// x 도시에서 출발해서 최단 거리가 정확히 k인 모든 도시의 번호를 출력하라.

// 입력:  4 4 2 1   -> 도시의 개수 n, 도로의 개수 m, 최단 거리 k, 출발 도시의 번호 x
//       1 2       -> a에서 b로 가는 도로가 존재한다.
//       1 3
//       2 3
//       2 4
// 출력:  4        -> x에서 출발해서 최단 거리가 k인 모든 도시의 번호를 오름차순으로 출력. 없으면 -1

// 입력:   4 3 2 1
//        1 2
//        1 3
//        1 4
// 출력:   -1

// 입력:   4 4 1 1
//        1 2
//        1 3
//        2 3
//        2 4
// 출력:   2
//        3

const int CITY_COUNT_MAX = 3000001;
vector<int> graph[CITY_COUNT_MAX];
bool visited[CITY_COUNT_MAX];
int cityNum, roadNum, goalCost, startCity, a, b;
vector<int> result;

void BFS()
{
    queue<pair<int, int>> q; // {cost, from}
    q.push({0, startCity});
    visited[startCity] = true;
    
    while(q.empty() == false)
    {
        int from = q.front().second;
        int fromCost = q.front().first;
        q.pop();
        
        if (goalCost == fromCost)
        {
            result.push_back(from);
            continue;
        }
        
        for (int i = 0; i < graph[from].size(); i++)
        {
            int to = graph[from][i];
            int toCost = fromCost + 1;
            
            if (visited[to] == true) continue;
            
            visited[to] = true;
            q.push({toCost, to});
        }
    }
}

int main()
{
    cin >> cityNum >> roadNum >> goalCost >> startCity;
    
    for (int i = 0; i < roadNum; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    BFS();
    
    if (result.size() == 0)
    {
        cout << -1 << '\n';
        return 0;
    }
    
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << '\n';
}
