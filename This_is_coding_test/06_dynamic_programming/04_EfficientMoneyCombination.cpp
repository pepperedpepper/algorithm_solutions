#include <iostream>
using namespace std;

// n가지 종류의 화폐가 있을 때, m을 만들기 위해 필요한 최소한의 화폐 개수
// 순서는 상관하지 않는다.

// 입력:   2 15   -> 화폐의 종류 n, 목표 합 m
//        2      -> 화폐의 값
//        3
// 출력:   5      -> 목표 합을 위해 최소한으로 사용하는 화폐의 개수

// 입력:   3 4
//        3
//        5
// 출력:   7

const int COIN_COUNT_MAX = 100;
const int SUM_MAX = 10001;

int coins[COIN_COUNT_MAX];
int dp[SUM_MAX];

int coinCount, sumTarget, curMinCount, prevTarget;

void FindMinCoinCount()
{
    for (int target = 1; target <= sumTarget; target++)
    {
        curMinCount = SUM_MAX;
        for (int i = 0; i < coinCount; i++)
        {
            prevTarget = target - coins[i];
            if (0 <= prevTarget && dp[prevTarget] != 0)
                curMinCount = min(curMinCount, dp[prevTarget]);
        }
        
        if (curMinCount != SUM_MAX)
            dp[target] = curMinCount + 1;
    }
}

int main()
{
    cin >> coinCount >> sumTarget;
    
    for (int i = 0; i < coinCount; i++)
    {
        cin >> coins[i];
        dp[coins[i]] = 1;
    }
    
    FindMinCoinCount();
    
    if (dp[sumTarget] == 0) cout << -1 << '\n';
    else                    cout << dp[sumTarget] << '\n';
}
