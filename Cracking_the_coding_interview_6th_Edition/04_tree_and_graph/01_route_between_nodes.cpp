#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 4.1 Route Between Nodes:
// Given a directed graph, design an algorithm to find out whether there is a route between two nodes.

bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int curNode, int goalNode)
{
    if (curNode == goalNode) return true;
    
    for (int i = 0; i < graph[curNode].size(); i++)
    {
        int nextNode = graph[curNode][i];
        
        if (visited[nextNode] == true) continue;
        
        visited[nextNode] = true;
        
        bool res = dfs(graph, visited, nextNode, goalNode);
        if (res == true) return true;
        
        visited[nextNode] = false;
    }
    
    return visited[goalNode];
}

bool bfs(vector<vector<int>>& graph, vector<bool>& visited, int startNode, int goalNode)
{
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    
    while(q.empty() == false)
    {
        int curNode = q.front();
        q.pop();
        
        for (int i = 0; i < graph[curNode].size(); i++)
        {
            int nextNode = graph[curNode][i];
            
            if (nextNode == goalNode) return true;
            if (visited[nextNode] == true) continue;
            
            visited[nextNode] = true;
            q.push(nextNode);
        }
    }
    
    return false;
}


int main()
{
    vector<vector<int>> graph =
    {
        { 1 },
        { 0, 3, 4 },
        { 3 },
        { 1, 2 },
        { 1 }
    };
    
    vector<bool> visited(5);
    cout << (dfs(graph, visited, 0, 2) == true ? "TRUE" : "FALSE") << endl;
    
    fill(visited.begin(), visited.end(), false);
    cout << (bfs(graph, visited, 0, 2) == true ? "TRUE" : "FALSE") << endl;
}
