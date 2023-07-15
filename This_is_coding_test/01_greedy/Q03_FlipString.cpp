#include <iostream>
using namespace std;

// 0과 1로만 이루어진 문자열 s가 있다.
// 연속된 하나 이상의 숫자를 모두 뒤집는 스킬을 사용해서 모두 같은 숫자를 만드려고 한다.
// 이 때 행동의 최소 횟수는?

// 입력: 0001100  -> 문자열 s
// 출력: 1        -> 행동의 최소 횟수

string str;
int zeros = 0;
int ones = 0;

int main()
{
    cin >> str;
    
    int curNum;
    int prevNum = -1;
    for (int i = 0; i < str.size(); i++)
    {
        curNum = str[i] - '0';
        
        if (curNum != prevNum) (curNum == 0 ? zeros : ones)++;
        
        prevNum = curNum;
    }
    
    cout << min(zeros, ones) << '\n';
}
