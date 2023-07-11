#include <iostream>
using namespace std;

// 배열에 주어진 수들을 더해서 가장 큰 수를 만들어라.

// 입력:  5 8 3      <- 배열 크기 n, 숫자가 더해지는 전체 횟수 m, 반복 최대 횟수 k
//       2 4 5 4 6  <- 배열
// 출력:  46         <- 6 6 6 5 6 6 6 5

// 입력:  5 7 2
//       3 4 3 4 3
// 출력:  28

const int NUM_COUNT_MAX = 1000;
int nums[NUM_COUNT_MAX];
int numCount, addCount, sameCount;
int sumMaxResult = 0;

void findSumMax()
{
    sort(nums, nums + numCount);
    
    int first = nums[numCount - 1];
    int second = nums[numCount - 2];
    
    int bundleCount = (addCount / (sameCount + 1));
    
    sumMaxResult = (first * sameCount + second) * bundleCount;
    sumMaxResult += (addCount - (bundleCount * (sameCount + 1))) * first;
}

int main()
{
    cin >> numCount >> addCount >> sameCount;
    
    for (int i = 0; i < numCount; i++)
        cin >> nums[i];
    
    findSumMax();
    
    cout << sumMaxResult << '\n';
}
