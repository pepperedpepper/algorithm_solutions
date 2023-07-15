#include <iostream>
#include <queue>
using namespace std;

// n X n 크기의 시험관이 있다. 바이러스의 종류는 1 ~ k이다.
// 모든 바이러스는 1초마다 상, 하, 좌, 우로 증식하는데, 번호가 낮은 종류의 바이러스부터 증식한다.
// 만약 증식과정에서 이미 바이러스가 있다면 증식할 수 없다.
// s초 후에 (행 x, 열 y)에 존재하는 바이러스는?

// 입력:  3 3     -> 시험관의 크기 n, 바이러스의 종류 k
//       1 0 2   -> 시험관 정보 ( 0 = 바이러스 없음 )
//       0 0 0
//       3 0 0
//       2 3 2   -> 초 s, 행 x, 열 y (행, 열이 반대다....)
// 출력:  3       -> s초 뒤에 x, y 위치에 있는 바이러스 종류

// 입력:  3 3
//       1 0 2
//       0 0 0
//       3 0 0
//       1 2 2
// 출력:  0


const int MAP_SIZE_MAX = 201;
const int STEP_MAX = 4;
const pair<int, int> STEPS[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int map[MAP_SIZE_MAX][MAP_SIZE_MAX];
int mapSize, virusCount, targetSec, targetX, targetY;

struct MapInfo
{
    int virus;
    int sec;
    int x;
    int y;
    
    bool operator<(const MapInfo& m) const
    {
        if (sec != m.sec) return sec > m.sec;
        return virus > m.virus;
    }
};

priority_queue<MapInfo> q;

void BFS()
{
    while(q.empty() == false)
    {
        int fromSec = q.top().sec;
        int fromX = q.top().x;
        int fromY = q.top().y;
        int spreadingVirus = q.top().virus;
        q.pop();
        
        if (fromSec == targetSec)
        {
            break;
        }
        
        for (int i = 0; i < STEP_MAX; i++)
        {
            int toX = fromX + STEPS[i].first;
            int toY = fromY + STEPS[i].second;
            
            if (toX < 1 || toY < 1 || mapSize < toX || mapSize < toY) continue;
            if (map[toX][toY] != 0) continue;
            
            q.push({ spreadingVirus, fromSec + 1, toX, toY });
            map[toX][toY] = spreadingVirus;
        }
    }
}

int main()
{
    cin >> mapSize >> virusCount;
    
    for (int y = 1; y <= mapSize; y++)
    {
        for (int x = 1; x <= mapSize; x++)
        {
            cin >> map[x][y];
            
            if (map[x][y] != 0)
                q.push({ map[x][y], 0, x, y });
        }
    }

    cin >> targetSec >> targetX >> targetY;
    
    BFS();
    
    cout << map[targetY][targetX] << '\n';
}
