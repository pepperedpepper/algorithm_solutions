#include <iostream>
using namespace std;

// 무작위로 나열된 수열을 내림차순으로 정렬하기

// 입력:  3         -> 수열에 속한 수의 개수
//       15 27 12   -> 수열
// 출력:  27 15 12  -> 내림차순 정렬

const int NUM_COUNT_MAX = 500;
int nums[NUM_COUNT_MAX];
int numCount;

int main()
{
    cin >> numCount;
    
    for (int i = 0; i < numCount; i++)
        cin >> nums[i];
    
    sort(nums, nums + numCount, [](const int& a, const int& b){ return a > b; } );
    
    for (int i = 0; i < numCount; i++)
        cout << nums[i] << ' ';
    cout << '\n';
}
