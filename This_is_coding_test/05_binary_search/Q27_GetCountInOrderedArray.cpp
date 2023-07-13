#include <iostream>
#include <vector>
using namespace std;

// 오름차순으로 정렬된 수열이 있다. 여기서 x가 등장한 횟수를 세어라.
// 단, 시간복잡도 logN으로 설계하지 않으면 시간초과 판정을 받는다.

// 입력:  7 2             -> 원소 개수 n, 원소 x
//       1 1 2 2 2 2 3   -> 원소들
// 출력:  4               -> 원소들 중에 값이 x인 것의 개수

// 입력:   7 4
//        1 1 2 2 2 2 3
// 출력:   -1

vector<int> nums;
int inputNum, numCount, target, targetCount = 0;

void BS()
{
    int start = 0;
    int finish = numCount;
    int mid = 0;
    
    while(start <= finish)
    {
        mid = (start + finish) / 2;
        
        if (nums[mid] < target) start = mid + 1;
        else if (target < nums[mid]) finish = mid - 1;
        else break;
    }
    
    int idx = mid;
    while(nums[idx--] == target)
        targetCount++;
        
    idx = mid + 1;
    while(nums[idx++] == target)
        targetCount++;
}

int main()
{
    cin >> numCount >> target;
    
    for (int i = 0; i < numCount; i++)
    {
        cin >> inputNum;
        nums.push_back(inputNum);
    }
    
    BS();
    
    if(targetCount == 0) cout << -1 << '\n';
    else                 cout << targetCount << '\n';
}
