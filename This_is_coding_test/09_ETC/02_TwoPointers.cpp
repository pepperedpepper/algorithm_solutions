#include <iostream>
#include <vector>
using namespace std;


// 특정한 합을 가지는 부분 연속 수열 찾기
// 시작점과 끝점을 가리키는 투 포인터로 풀 수 있다.

// 1) start와 finish가 인덱스 0을 가리킨다.
// 2) 현재 부분합이 목표합과 같다면 카운트한다.
// 3) 현재 부분합이 목표합보다 작다면 finish를 1증기한다.
// 3) 현재 부분합이 목표합보다 크거나 같으면 start를 1증기한다.

int arrCount = 5;
int targetSum = 5;
int arr[] = {1, 2, 3, 2, 5};

int CountArrThatHasTheSameSum()
{
    int count = 0;
    int finish = 0;
    int curSum = 0;
    
    for (int start = 0; start < arrCount; start++)
    {
        while(finish < arrCount && curSum < targetSum)
            curSum += arr[finish++];
        
        if (curSum == targetSum) count++;
        
        curSum -= arr[start];
    }
    
    return count;
}


// 정렬되어 있는 두 리스트를 정렬된 상태로 합해라.

// 병합 정렬에서 이용되는 방식
// 1) 리스트 A에서 처리되지 않은 가장 작은 원소를 i가 가리킨다.
// 2) 리스트 B에서 처리되지 않은 가장 작은 원소를 j가 가리킨다.
// 3) A[i]와 B[j] 중에 작은 원소를 결과 리스트에 담는다.
// 시간복잡도: N + M

int aCount = 3;
int bCount = 4;
int a[] = {1, 3, 5};
int b[] = {2, 4, 6, 8};
vector<int> result;

void MergeTwoOrderedList()
{
    int ai = 0;
    int bi = 0;
    
    while(ai < aCount || bi < bCount)
    {
        // b의 모든 원소가 처리되었거나, a의 원소가 더 작을 때 (먼저 올 때)
        if (bCount <= bi || (ai < aCount && a[ai] <= b[bi]))
            result.push_back(a[ai++]); // a의 원소를 넣는다.

        // a의 모든 원소가 처리되었거나, b의 원소가 더 작을 때 (먼저 올 때)
        else
            result.push_back(b[bi++]); // b의 원소를 넣는다.
    }
    
    // (출력)
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';
    cout << '\n';
}


int main()
{
    cout << CountArrThatHasTheSameSum() << '\n';
    
    MergeTwoOrderedList();
}
