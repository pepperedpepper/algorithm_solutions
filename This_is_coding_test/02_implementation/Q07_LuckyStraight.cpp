#include <iostream>
using namespace std;

// 현재 캐릭터의 점수 n을 반으로 나눴을 때, 왼쪽 부분의 합과 오른쪽 부분의 합이 동일하면 럭키스트레이트를 쓸 수 있다.

// 입력: 123402  -> 점수 n
// 출력: LUCKY   -> 럭키 스트레이트 사용 가능 여부

// 입력: 7755
// 출력: READY

string str;
int strSize;
int sum = 0;

int main()
{
    cin >> str;
    
    strSize = str.size();
    for (int i = 0; i < strSize / 2; i++)
    {
        sum += str[i] - '0';
        sum -= str[strSize - i - 1] - '0';
    }
    
    if (sum == 0) cout << "LUCKY\n";
    else          cout << "READY\n";
}
