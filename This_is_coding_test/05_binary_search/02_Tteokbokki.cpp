#include <iostream>
using namespace std;

// 적어도 m만큼의 길이를 얻기 위해 설정할 수 있는 절단기의 최대 높이는?

// 입력:   4 6          -> 전체 떡의 개수 n, 요청한 떡의 길이 m
//        19 15 10 17  -> 떡들의 개별 높이
// 출력:   15           -> 절단기에 설정할 수 있는 최대 높이 값

const int TTEOK_COUNT_MAX = 1000000;
int tteoks[TTEOK_COUNT_MAX];
int tteokCount, tteokOrder, maxCutterHeight = 0;

int GetTteokLength(int cutterHeight)
{
    int result = 0;
    for (int i = 0; i < tteokCount; i++)
        result += max(0, tteoks[i] - cutterHeight);
    
    return result;
}

void FindMaxCutterHeight()
{
    int minHeight = tteoks[tteokCount - 1] - tteokOrder;
    int maxHeight = tteoks[tteokCount - 1];
    int midHeight = 0;
    int midTteok = 0;
    
    while(minHeight <= maxHeight)
    {
        midHeight = (minHeight + maxHeight) / 2;
        midTteok = GetTteokLength(midHeight);
        
        // too much
        if (tteokOrder < midTteok)
        {
            maxCutterHeight = midHeight;
            minHeight = midHeight + 1;
        }
        // too less
        else if (midTteok < tteokOrder)
        {
            maxHeight = midHeight - 1;
        }
        else
        {
            maxCutterHeight = midHeight;
            return;
        }
    }
}

int main()
{
    cin >> tteokCount >> tteokOrder;
 
    for (int i = 0; i < tteokCount; i++)
        cin >> tteoks[i];
    
    sort(tteoks, tteoks + tteokCount);
    
    FindMaxCutterHeight();
    
    cout << maxCutterHeight << '\n';
}
