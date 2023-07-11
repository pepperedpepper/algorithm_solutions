#include <iostream>
using namespace std;

// 손님이 필요한 부품이 있는지 여부?

// 입력:  5           -> 부품의 종류 수 n
//       8 3 7 9 2   -> 전체 부품 번호
//       3           -> 구입할 종류 수 m
//       5 7 9       -> 구입할 부품 번호
// 출력:  no yes yes   -> 구입할 부품이 있는지 여부

const int TOOL_COUNT_MAX = 1000000;
int tools[TOOL_COUNT_MAX];
int toolCount, requestedToolCount, requestedTool;

bool FindTool(const int& target)
{
    int first = 0;
    int last = toolCount - 1;
    
    while(first <= last)
    {
        int mid = (first + last) / 2;
        
        if (target < tools[mid])      last = mid - 1;
        else if (tools[mid] < target) first = mid + 1;
        else                          return true;
    }
    return false;
}

int main()
{
    cin >> toolCount;
    for (int i = 0; i < toolCount; i++)
        cin >> tools[i];
        
    sort(tools, tools + toolCount); // ascending

    cin >> requestedToolCount;
    for (int i = 0; i < toolCount; i++)
    {
        cin >> requestedTool;
        
        if (true == FindTool(requestedTool)) cout << "yes ";
        else                                 cout << "no ";
        
    }
    cout << '\n';
}
