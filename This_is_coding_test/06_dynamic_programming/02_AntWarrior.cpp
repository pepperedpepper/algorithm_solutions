#include <iostream>
using namespace std;

// 개미전사는 메뚜기 정찰병에게 들키지 않기 위해 최소한 한 칸씩 띄워서 식량창고를 털어야 한다.
// 최대한 털 수 있는 식량의 양은?

// 입력:   4         -> 식량창고의 개수 n
//        1 3 1 5   -> 식량창고에 저장된 식량의 개수
// 출력:   8         -> 개미 전사가 얻을 수 있는 식량의 최댓값

// 입력:   4
//        3 2 1 1
// 출력:   4

const int MAX_STORAGE = 100;
int storages[MAX_STORAGE];
int dp[MAX_STORAGE];
int storageCount;

void FindMaxFoodAmount()
{
    dp[0] = storages[0];
    dp[1] = max(dp[0], storages[1]);
    
    for (int i = 2; i < storageCount; i++)
        dp[i] = max(dp[i - 2] + storages[i], dp[i - 1]);
}

int main()
{
    cin >> storageCount;
    
    for (int i = 0; i < storageCount; i++)
        cin >> storages[i];
    
    FindMaxFoodAmount();
    
    cout << dp[storageCount - 1] << '\n';
}
