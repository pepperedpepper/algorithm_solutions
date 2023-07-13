#include <iostream>
#include <queue>
using namespace std;

// 1번부터 n번까지의 강의를 듣고자 한다. 동시에 여러개의 강의를 들을 수 있다고 가정한다.
// 1번부터 n번까지 각각의 강의를 듣는데 걸리는 최소 시간은?

// 입력:  5         -> 들을 강의 수 n
//       10 -1     -> 강의시간, { 선수 강의번호 ... }, -1로 종료
//       10 1 -1
//       4 1 -1
//       4 3 1 -1
//       3 3 -1
// 출력:  10        -> 수강에 걸리는 최소 시간
//       20
//       14
//       18
//       17



const int CLASS_COUNT_MAX = 501;
int indegree[CLASS_COUNT_MAX];
int times[CLASS_COUNT_MAX];
vector<int> graph[CLASS_COUNT_MAX];
int classCount, classTime, prevClass;

void TopologySort()
{
    priority_queue<pair<int, int>> q;
    
    for (int i = 1; i <= classCount; i++)
        if (indegree[i] == 0)
            q.push({-times[i], i});
    
    while(q.empty() == false)
    {
        int from = q.top().second;
        int fromTime = -q.top().first;
        q.pop();
        
        for (int i = 0; i < graph[from].size(); i++)
        {
            int to = graph[from][i];
            int toTime = times[to];
            indegree[to]--;
            
            if (indegree[to] != 0) continue;
            
            times[to] = fromTime + toTime;
            q.push({-times[to], to});
        }
    }
}

int main()
{
    cin >> classCount;
    
    for (int i = 1; i <= classCount; i++)
    {
        cin >> classTime;
        
        times[i] = classTime;
        
        while(cin >> prevClass)
        {
            if (prevClass == -1) break;
            
            graph[prevClass].push_back(i);
            indegree[i]++;
        }
    }
    
    TopologySort();
    
    for (int i = 1; i <= classCount; i++)
        cout << times[i] << '\n';
}
