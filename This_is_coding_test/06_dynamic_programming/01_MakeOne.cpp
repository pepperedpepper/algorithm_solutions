#include <iostream>
using namespace std;

// 정수 x가 다음과 같은 연산을 할 수 있을 때, 1을 만드는 최소 연산 횟수는?
//     1. x가 5로 나누어 떨어지면, 5로 나눈다.
//     2. x가 3으로 나누어 떨어지면, 3으로 나눈다.
//     3. x가 2로 나누어 떨어지면, 2로 나눈다.
//     4. x에서 1을 뺀다.

// 입력:   26  -> 정수x
// 출력:   3   -> 최소 연산 횟수

const int NUM_COUNT_MAX = 30000;
int dp[NUM_COUNT_MAX]; // dp[숫자] = 해당 숫자를 만드는 최소 연산 횟수 
int num;

void FindMinOperationCount()
{
    for (int x = 2; x <= num; x++)
    {
        dp[x] = dp[x - 1] + 1;
        
        if (x % 2 == 0)
            dp[x] = min(dp[x], dp[x / 2] + 1);
        
        if (x % 3 == 0)
            dp[x] = min(dp[x], dp[x / 3] + 1);
        
        if (x % 5 == 0)
            dp[x] = min(dp[x], dp[x / 5] + 1);
    }
}

int main()
{
    cin >> num;
    
    FindMinOperationCount();
    
    cout << dp[num] << '\n';
}
