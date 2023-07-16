#include <iostream>
using namespace std;

// 0 ~ n-1번의 집이 존재한다.
// 모든 도로에는 가로등이 있는데 하루동안 켜기 위한 비용은 도로의 길이와 똑같다.
// 일부 가로등을 비활성화 해서 최대한 많은 금액을 절약하고자 한다.

// 입력:   7 11    -> 집의 수 n, 도로의 수 m
//        0 1 7   -> a번 집과 b번 집 사이에 양방향 도로가 있고, 그 길이는 c이다.
//        0 3 5
//        1 2 8
//        1 3 9
//        1 4 7
//        2 4 5
//        3 4 15
//        3 5 6
//        4 5 8
//        4 6 9
//        5 6 11
// 출력:   51      -> 일부 가로등을 비활성화해서 절약 할 수 있는 최대 금액

struct Road
{
    int a, b, cost;
    
    bool operator<(const Road& r) const
    {
        return cost < r.cost;
    }
};

const int HOUSE_COUNT_MAX = 200001;
vector<Road> roads;
int parent[HOUSE_COUNT_MAX];
int houseCount, roadCount, a, b, cost;
int totalCost = 0, resultCost = 0;


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
    
    for (int i = 0; i < roadCount; i++)
    {
        cin >> a >> b >> cost;
        roads.push_back({a, b, cost});
    }
    
    sort(roads.begin(), roads.end());
    
    for (int i = 0; i < houseCount; i++)
        parent[i] = i;
    
    for (int i = 0; i < roadCount; i++)
    {
        int a = roads[i].a;
        int b = roads[i].b;
        
        int pa = FindParent(a);
        int pb = FindParent(b);
        
        totalCost += roads[i].cost;
        
        if (pa == pb) continue;
        
        Union(a, b);

        resultCost += roads[i].cost;
    }
    
    cout << totalCost - resultCost << '\n';
}
