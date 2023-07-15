#include <iostream>
using namespace std;

// 0 ~ 9로 이루어진 문자열 s가 주어졌을 때, 곱하기 혹은 더하기 연산으로 가장 큰 수를 만들면?
// 단, 연산 순서는 왼쪽에서 순서대로 이루어진다. (곱하기 먼저 아님)

// 입력: 02984   -> 하나의 문자열 s
// 출력: 576     -> 만들 수 있는 가장 큰 수

string str;
int cur;
long long result = 0;

int main()
{
    cin >> str;
    
    result = str[0] - '0';
    for (int i = 1; i < str.size(); i++)
    {
        cur = str[i] - '0';
        
        if (cur <= 1 || result <= 1) result += cur;
        else                         result *= cur;
    }
    
    cout << result << '\n';
}
