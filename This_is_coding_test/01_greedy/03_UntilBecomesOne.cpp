#include <iostream>
using namespace std;

// 특정 수 n이 1이 될 때까지 다음 두 과정을 최소한으로 사용하는 횟수는?
//     1) n에서 1을 뺀다.
//     2) n을 k로 나눈다.

// 입력:  17 4   <- 특정 수 n, 나누는 수 k
// 출력:  3      <- 1번>2번>2번

// 입력:  25 5
// 출력:  2

int num, divider, minOperationCount = 0;

int main()
{
    cin >> num >> divider;
    
    while(true)
    {
        // divider로 나누어 떨어지는 가장 큰 수 : target
        int target = (num / divider) * divider;
        // target이 되는 만큼 -1 하기
        minOperationCount += (num - target);
        num = target;
        
        // 더 이상 나눌 수 없을 때 반복문 탈출
        if (num < divider) break;
        
        // divider로 나누기
        num /= divider;
        minOperationCount++;
    }
    
    // 마지막으로 남은 수에 대하여 -1 하기
    minOperationCount += (num - 1);
    
    cout << minOperationCount << '\n';
}
