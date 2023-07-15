#include <iostream>
using namespace std;

// 안테나를 설치하려고 한다.
// 안테나로부터 모든 집까지의 거리의 총합이 최소가 되는 지점은?

// 입력:  4        -> 집의 수 n
//       5 1 7 9  -> 각 집의 위치 지점
// 출력:  5       -> 안테나를 설치할 위치 지점. 거리의 총합이 같다면, 가장 작은 수 출력.

vector<int> houses;
int houseNum, input, resultHouseNum;

int main()
{
    cin >> houseNum;
    
    for (int i = 0; i < houseNum; i++)
    {
        cin >> input;
        houses.push_back(input);
    }
    
    sort(houses.begin(), houses.end());
    
    cout << houses[(houseNum - 1) / 2] << '\n';
}
