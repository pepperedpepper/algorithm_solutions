#include <iostream>
using namespace std;

// n개의 동전을 이용해서 만들 수 없는 야으이 정수 금액 중 최솟값은?

// 입력: 5          -> 동전의 개수 n
//      3 2 1 1 9  -> 동전의 화폐 단위들
// 출력: 8          -> 주어진 동전들로 만들 수 없는 양의 정수 금액 중 최솟값

// 입력: 3
//      3 5 7
// 출력: 1

const int COIN_COUNT_MAX = 1001;
int coinCount;
int coins[COIN_COUNT_MAX];

int main()
{
    cin >> coinCount;
    
    for (int i = 0; i < coinCount; i++)
        cin >> coins[i];
    
    sort(coins, coins + coinCount);
    
    // ...
}
