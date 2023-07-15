#include <iostream>
using namespace std;

// 집 n개가 수직선 위에 있다. 각 집의 좌표는 다르다.
// 최대한 많은 곳에서 와이파이를 쓰기 위해서, 가장 인접한 두 공유기 사이의 거리를 최대한으로 하고자 한다.
// 총 c개의 공유기를 설치할 때, 최대 거리는?

// 입력:  5 3  -> 집의 개수 n, 공유기 개수 c
//       1    -> 집의 좌표들
//       2
//       8
//       4
//       9
// 출력:  3    -> 가장 인접한 두 공유기 사이의 최대 거리

int houseCount, wifiCount, input;
vector<int> houses;
int minGapResult = 1e9;

void FindMaxDistance()
{
    // 집 마다 떨어진 gap
    int startGap = 1;
    int finishGap = houses[houseCount - 1] - houses[0];
    int midGap;
    
    while(startGap <= finishGap)
    {
        midGap = (startGap + finishGap) / 2;
        
        int curWifiCount = 1;
        int prevHouse = houses[0];
        for (int i = 1; i < houses.size(); i++)
        {
            // midGap이상 떨어진 위치이면 카운트
            if (prevHouse + midGap <= houses[i])
            {
                prevHouse = houses[i];
                curWifiCount++;
            }
        }
        
        if (wifiCount <= curWifiCount)
        {
            startGap = midGap + 1;
            minGapResult = midGap;
        }
        else if (curWifiCount < wifiCount)
        {
            finishGap = midGap - 1;
        }
    }
}

int main()
{
    cin >> houseCount >> wifiCount;
    
    for (int i = 0; i < houseCount; i++)
    {
        cin >> input;
        houses.push_back(input);
    }
    
    sort(houses.begin(), houses.end());
    
    FindMaxDistance();
    
    cout << minGapResult << '\n';
}
