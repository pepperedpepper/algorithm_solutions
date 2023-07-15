#include <iostream>
using namespace std;

const int ARR_SIZE = 5;
int arr[] = {0, 10, 20, 30, 40, 50};
int prefixSum[ARR_SIZE];

// 인덱스: 0   1   2   3   4   5
// 데이터:     10  20  30  40  50
// 구간합: 0   10  30  60  100 150

// 접두사 합은 리스트 맨 앞부터 특정 위치까지의 합을 구해 놓은 것이다.
// 접두사 합을 미리 구해 놓음으로써 특정 위치에서 특정 위치까지의 합을 1의 시간복잡도 만에 구할 수 있다.

int GetPrefixSum(int from, int to)
{
    // 접두사 합 미리 구해놓기
    for (int i = 1; i <= ARR_SIZE; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    
    // 결과값
    // 3 ~ 4의 구간합은: 4까지의 구간합 - 2까지의 구간합 = 70
    return prefixSum[to] - prefixSum[from - 1];
}

int main()
{
    int from, to;
    cin >> from >> to;
    
    cout << GetPrefixSum(from, to) << '\n';
}
