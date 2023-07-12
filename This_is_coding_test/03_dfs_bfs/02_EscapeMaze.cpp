#include <iostream>
#include <queue>
using namespace std;

// n x m 크기의 직사각형 형태의 미로에 갖혀 있다.
// 현재 위치는 (1, 1)이고 미로의 출구는 (n, m)이다.
// 탈출하기 위해 움직여야 하는 최소 칸의 개수는?
// 괴물 있는 곳-0, 없는 곳-1

// 입력: 5 6     -> n행 m열
//      101010  -> 미로 정보
//      111111
//      000001
//      111111
//      111111
// 출력:  10      -> 이동한 최소 칸의 개수

enum { MONSTER, SAFE };
const int MAZE_SIZE_MAX = 201;
const int START_POS = 1;
const int STEP_MAX = 4;
const pair<int, int> STEP[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int map[MAZE_SIZE_MAX][MAZE_SIZE_MAX];
int lastX, lastY;

void BFS()
{
    queue<pair<int, int>> q;
    q.push({START_POS, START_POS});
    map[START_POS][START_POS] = 1;
    
    while(q.empty() == false)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < STEP_MAX; i++)
        {
            int curX = x + STEP[i].first;
            int curY = y + STEP[i].second;
            
            if (curX < 1 || curY < 1 || lastX < curX || lastY < curY) continue;
            if (map[curY][curX] == SAFE)
            {
                map[curY][curX] = map[y][x] + 1;
                q.push({curX, curY});
            }
        }
    }
}

int main()
{
    cin >> lastY >> lastX;
    
    for (int y = 1; y <= lastY; y++)
        for (int x = 1; x <= lastX; x++)
            scanf("%1d", &map[y][x]);
    
    BFS();
    
    cout << map[lastY][lastX] << '\n';
}
