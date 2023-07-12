#include <iostream>
using namespace std;

// n개의 원소로 구성된 배열 a, b에서 원소를 바꿔치기해서 배열 a의 합이 최대가 되도록해야한다.

// 입력:  5 3        -> 원소 개수 n, 최대 바꿔치기 연산 횟수 k
//       1 2 5 4 3  -> 배열 a
//       5 5 6 6 5  -> 배열 b
// 출력:  26         -> 배열 a의 모든 원소의 합의 최댓값

const int ARR_MAX = 100000;
int a[ARR_MAX];
int b[ARR_MAX];
int arrCount, swapCount;
long long resultSum = 0;

bool Bigger(const int& a, const int& b)
{
    return a > b;
}

int main()
{
    cin >> arrCount >> swapCount;
    
    for(int i = 0; i < arrCount; i++)
        cin >> a[i];
    
    for(int i = 0; i < arrCount; i++)
        cin >> b[i];
    
    sort(a, a + arrCount);
    sort(b, b + arrCount, Bigger);
    
    for (int i = 0; i < swapCount; i++)
    {
        if (a[i] < b[i]) swap(a[i], b[i]);
        else             break;
    }
    
    for(int i = 0; i < arrCount; i++)
        resultSum += a[i];
    
    cout << resultSum << '\n';
}
