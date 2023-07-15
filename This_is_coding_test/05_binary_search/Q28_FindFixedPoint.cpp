#include <iostream>
using namespace std;

// 고정점(Fixed Point)이란 수열의 원소 중에서 그 값이 인덱스와 동일한 원소이다.
// 어떤 수열의 원소가 오름차순으로 정렬되어 있을 때 고정점을 출력하라.
// 고정점은 최대 1개만 존재한다.
// 단, 시간 복잡도 log N 알고리즘으로 설계해야한다.

// 입력:  5             -> 원소의 개수 n
//       -15 -6 1 3 7  -> 원소들
// 출력:  3             -> 고정점 출력. 없으면 -1

// 입력:  7
//       -15 -4 2 8 9 13 15
// 출력:  2

// 입력:  7
//       -15 -4 3 8 9 13 15
// 출력:  -1

vector<int> nums;
int numCount, input, fixedPoint = -1;

void FindFixedPoint()
{
    int start = 0;
    int finish = numCount - 1;
    int mid = 0;
    
    while(start <= finish)
    {
        mid = (start + finish) / 2;
        
        if (nums[mid] == mid)
        {
            fixedPoint = mid;
            return;
        }
        else if (nums[mid] < mid) start = mid + 1;
        else                      finish = mid - 1;
    }
}

int main()
{
    cin >> numCount;
    
    for (int i = 0; i < numCount; i++)
    {
        cin >> input;
        nums.push_back(input);
    }
    
    FindFixedPoint();
    
    cout << fixedPoint << '\n';
}
