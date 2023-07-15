#include <iostream>
using namespace std;

// 바이러스는 상하좌우로 퍼진다.
// 새로 벽을 3개 세울 수 있을 때, 바이러스가 퍼질 수 없는 안전 영역의 최대 개수는?

// 입력: 7 7             -> 세로 크기 n, 가로 크기 m
//      2 0 0 0 1 1 0   -> 0 빈칸, 1 벽, 2 바이러스
//      0 0 1 0 1 2 0
//      0 1 1 0 1 0 0
//      0 1 0 0 0 0 0
//      0 0 0 0 0 1 1
//      0 1 0 0 0 0 0
//      0 1 0 0 0 0 0
// 출력: 27              -> 얻을 수 있는 안전 영역의 최대 크기

// 입력: 4 6
//      0 0 0 0 0 0
//      1 0 0 0 0 2
//      1 1 1 0 0 2
//      0 0 0 0 0 2
// 출력: 9

// 입력: 8 8
//      2 0 0 0 0 0 0 2
//      2 0 0 0 0 0 0 2
//      2 0 0 0 0 0 0 2
//      2 0 0 0 0 0 0 2
//      2 0 0 0 0 0 0 2
//      0 0 0 0 0 0 0 0
//      0 0 0 0 0 0 0 0
//      0 0 0 0 0 0 0 0
// 출력: 3

const int WALL_COUNT_MAX = 3;
const int MAP_SIZE_MAX = 8;
const int STEP_MAX = 4;
const pair<int, int> STEPS[] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
enum { EMPTY, WALL, VIRUS };

int map[MAP_SIZE_MAX][MAP_SIZE_MAX];
int virus[MAP_SIZE_MAX][MAP_SIZE_MAX];
int width, height;
int safeAreaMax = 0;

void SpreadVirus(int x, int y)
{
    virus[y][x] = VIRUS;
    
    for (int i = 0; i < STEP_MAX; i++)
    {
        int curX = x + STEPS[i].first;
        int curY = y + STEPS[i].second;
        
        if (curX < 0 || curY < 0 || width <= curX || height <= curY) continue;
        if (virus[curY][curX] != EMPTY) continue;
        
        SpreadVirus(curX, curY);
    }
}

int GetSafeCount()
{
    int count = 0;
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            if (virus[y][x] == EMPTY)
                count++;
    
    return count;
}

void InstallWalls(int wallCount)
{
    if (wallCount == WALL_COUNT_MAX)
    {
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++)
                virus[y][x] = map[y][x];
        
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++)
                if (virus[y][x] == VIRUS)
                    SpreadVirus(x, y);
        
        safeAreaMax = max(safeAreaMax, GetSafeCount());
    
        return;
    }
    
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (map[y][x] != EMPTY) continue;
            
            map[y][x] = WALL;
            InstallWalls(wallCount + 1);
            map[y][x] = EMPTY;
        }
    }
}

int main()
{
    cin >> height >> width;
    
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            cin >> map[y][x];
    
    InstallWalls(0);
            
    cout << safeAreaMax << '\n';
}
