#include <iostream>
using namespace std;

// n X m (행 X 열)크기의 금광이 있다. 첫 번째 열 아무데서나 출발해서 금광을 캘 때 얻을 수 있는 금의 최대 크기는?
// 이동 방식
//        1. 오른쪽 위
//        2. 오른쪽
//        3. 오른쪽 아래

// 입력:   1                         -> 테스트 케이스 개수
//        3 4                       -> n, m
//        1 3 3 2 2 1 4 1 0 6 4 7   -> 매장된 금의 개수
// 출력:   19                        -> 얻을 수 있는 금의 최대 크기

// 입력:   1
//        4 4
//        1 3 1 5 2 2 4 1 5 0 2 3 0 6 1 2
// 출력:   16

const int MAP_HEIGHT_MAX = 4;
const int MAP_WIDTH_MAX = 1001;
int caseCount, height, width, curMax;
int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];


int main()
{
    cin >> caseCount;
    
    for (int c = 0; c < caseCount; c++)
    {
        cin >> height >> width;
        
        for (int h = 1; h <= height; h++)
            for (int w = 1; w <= width; w++)
                cin >> map[h][w];
        
        for (int w = 2; w <= width; w++)
        {
            map[1][w] += max(map[1][w-1], map[2][w-1]);
            map[2][w] += max(map[1][w-1], max(map[2][w-1], map[3][w-1]));
            map[3][w] += max(map[2][w-1], map[3][w-1]);
        }
        
        curMax = 0;
        for (int h = 1; h < MAP_HEIGHT_MAX; h++)
            curMax = max(curMax, map[h][width]);
        
        cout << curMax << '\n';
    }
}
