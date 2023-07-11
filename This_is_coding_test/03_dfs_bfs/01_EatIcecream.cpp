#include <iostream>
using namespace std;

// n x m 크기의 얼음 틀에서 구멍이 뚫린 부분인 0이 이어져 있으면 아이스크림 1개를 만들 수 있다.
// 주어진 얼음 틀에서 만들 수 있는 아이스크임의 총 개수는?

// 입력: 4 5   -> 4 x 5 얼음 틀
//      00110 -> 얼음 틀
//      00011
//      11111
//      00000
// 출력: 3     -> 아이스크림 총 개수

const int MAP_MAX = 1001;
const int NO_ICECREAM = 1;
const int STEP_MAX = 4;
const pair<int, int> STEPS[STEP_MAX] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int map[MAP_MAX][MAP_MAX];

int width, height;
int icecreamCountResult = 0;

void DFS(int x, int y)
{
    map[y][x] = NO_ICECREAM;
    
    for (int i = 0; i < STEP_MAX; i++)
    {
        int curX = x + STEPS[i].first;
        int curY = y + STEPS[i].second;
        
        if (curX < 0 || curY < 0 || width <= curX || height <= curY) continue;
        if (map[curY][curX] == NO_ICECREAM) continue;
        
        DFS(curX, curY);
    }
}

int main()
{
    cin >> height >> width;
    
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            scanf("%1d", &map[y][x]);
    
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (map[y][x] == NO_ICECREAM) continue;
            
            DFS(x, y);
            
            icecreamCountResult++;
        }
    }
    
    cout << icecreamCountResult << '\n';
}
