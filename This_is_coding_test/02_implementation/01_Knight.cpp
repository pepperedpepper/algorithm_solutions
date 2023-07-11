#include <iostream>
using namespace std;

// 8 x 8 체스판 위에서 나이트가 이번에 이동할 수 있는 경우의 수는?
// 행번호는 1 ~ 8이며, 열번호는 a ~ h이다.
// 이동 방향
//     1) 수평 2칸 > 수직 1칸
//     2) 수직 2칸 > 수평 1칸

// 입력:  c2  -> 현재 위치
// 출력:  6   -> 현재 위치에서 이동할 수 있는 경우의 수

const int POSITION_MAX = 8;
const int STEP_MAX = 8;
const pair<int, int> STEPS[STEP_MAX] = { {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2} };
int nowX, nowY;
int moveCountResult = 0;

void findmoveCountMax()
{
    for (int i = 0; i < STEP_MAX; i++)
    {
        int curX = nowX + STEPS[i].first;
        int curY = nowY + STEPS[i].second;
        
        if (curX < 1 || curY < 1 || POSITION_MAX < curX || POSITION_MAX < curY) continue;
        
        moveCountResult++;
    }
}

int main()
{
    char inputY;
    cin >> inputY >> nowX;
    nowY = inputY - 'a' + 1;
    
    findmoveCountMax();
    
    cout << moveCountResult << '\n';
}
