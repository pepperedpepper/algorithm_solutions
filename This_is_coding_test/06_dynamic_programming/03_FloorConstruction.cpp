#include <iostream>
using namespace std;

// 가로 n X 세로 2 인 바닥이 있다.
// ( 1 X 2 ), ( 2 X 1 ), ( 2 X 2 ) 덮개로 이 바닥을 채우려고 한다.
// 이 때 바닥을 채우는 모든 경우의 수는?

// 입력:   3  -> 가로길이 n
// 출력:   5  -> 바닥을 채우는 모든 경우의 수

const int WIDTH_MAX = 10001;
const int DIVIDER = 796796;
int dp[WIDTH_MAX];
int width;

void FindAllPossibleWays()
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    
    for (int i = 3; i <= width; i++)
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % DIVIDER;
}

int main()
{
    cin >> width;
    
    FindAllPossibleWays();
    
    cout << dp[width] << '\n';
}
