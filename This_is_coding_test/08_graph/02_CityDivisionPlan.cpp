#include <iostream>
using namespace std;

// 마을을 2개로 분리하면서 유지비의 합이 최소가 되도록 만들자.
// 양방향 연결되어 있다.

// 입력:   7 12   -> 집의 개수 n, 길의 개수 m
//        1 2 3  -> 집 a, 집 b, 두 집을 연결하는 유지비 c
//        1 3 2
//        3 2 1
//        2 5 2
//        3 4 4
//        7 3 6
//        5 1 5
//        1 6 2
//        6 4 1
//        6 5 3
//        4 5 3
//        6 7 4
// 출력:   8       -> 길을 없애고 남은 유지비 합의 최솟값

struct Edge
{
    int cost;
    int a;
    int b;
    
    bool operator<(const Edge& e) const
    {
        return cost < e.cost;
    }
};

const int HOUSE_COUNT_MAX = 100001;
int parent[HOUSE_COUNT_MAX];
vector<Edge> edges;
int houseCount, roadCount, a, b, cost;
int totalCost = 0, maxCost = 0;

int FindParent(int x)
{
    if (x == parent[x]) return x;
    return parent[x] = FindParent(parent[x]);
}

void Union(int a, int b)
{
    a = parent[a];
    b = parent[b];
    
    if (a < b) parent[b] = a;
    else       parent[a] = b;
}

int main()
{
    cin >> houseCount >> roadCount;
    
    for (int i = 1; i <= houseCount; i++)
        parent[i] = i;
    
    for (int i = 0; i < roadCount; i++)
    {
        cin >> a >> b >> cost;
        edges.push_back({cost, a, b});
    }
    
    sort(edges.begin(), edges.end());
    
    for (int i = 0; i < edges.size(); i++)
    {
        a = edges[i].a;
        b = edges[i].b;
        cost = edges[i].cost;
        
        if (FindParent(a) == FindParent(b)) continue;
        
        Union(a, b);
        totalCost += cost;
        maxCost = max(maxCost, cost);
    }
    
    cout << totalCost - maxCost << '\n';
}
