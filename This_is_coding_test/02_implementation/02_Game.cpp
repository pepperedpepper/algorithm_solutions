#include <iostream>
using namespace std;

// 캐릭터의 움직임 매뉴얼
//     1) 캐릭터의 회전 방향의 왼쪽 방향부터 차례로 살펴본다
//     2) 살펴봤는데 갈 수 없다면 회전만 한다
//     3) 모두 가봤거나 바다여서 갈 수 없다면 이전 뒤로 간다
//     4) 뒤가 바다이면 종료한다
// 방향
//     0-북쪽, 1-동쪽, 2-남쪽, 3-서쪽
// 땅 정보
//     0-육지, 1-바다
// 이 때 캐릭터가 방문한 칸의 수?

// 입력:  4 4       -> 4 x 4 맵 생성
//       1 1 0     -> (1, 1)위치에서 북쪽(0)을 바라보고 있는 캐릭터
//       1 1 1 1   -> 첫 줄은 모두 바다이다.
//       1 0 0 1
//       1 1 0 1
//       1 1 1 1
// 출력:  3         -> 방문한 칸의 수

const int MAP_MAX = 50;
enum { NORTH, EAST, SOUTH, WEST, MAXDIR };
enum { LAND, SEA };
const pair<int, int> MOVE[] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int map[MAP_MAX][MAP_MAX];
bool visited[MAP_MAX][MAP_MAX];
int width, height, startX, startY, startDir;
int moveCount = 0;

bool CanGo(int x, int y)
{
    return (x < 0 || y < 0 || width <= x || height <= y || map[y][x] == SEA) == false;
}

void Move()
{
    int x = startX;
    int y = startY;
    int dir = startDir;
    bool noPass = true;
    
    while(true)
    {
        moveCount++;
        visited[y][x] = true;
        noPass = true;
        
        for (int i = 0; i < MAXDIR; i++)
        {
            // turn
            dir = (dir + 1) % MAXDIR;
            
            int curX = x + MOVE[i].first;
            int curY = y + MOVE[i].second;
            
            if (CanGo(curX, curY) == false) continue;
            if (visited[curY][curX] == true) continue;
            
            // move
            x = curX;
            y = curY;
            
            noPass = false;
            break;
        }
        
        if (noPass == true)
        {
            // or move back
            int back = (dir + 2) % MAXDIR;
            x += MOVE[back].first;
            y += MOVE[back].second;
            
            if (CanGo(x, y) == false) return;
        }
    }
}

int main()
{
    cin >> height >> width >> startY >> startX >> startDir;
    
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            cin >> map[y][x];
    
    Move();
    
    cout << moveCount << '\n';
}
