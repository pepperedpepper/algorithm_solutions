#include <iostream>
using namespace std;

// 알파벳 대문자, 숫자(0~9)로 구성된 문자열 s가 있다.
// 모든 알파벳을 오름차순으로 정렬해서 출력한 뒤에 모든 숫자를 더한 값을 이어서 출력하라.

// 입력:  K1KA5CB7  -> 문자열 s
// 출력:  ABCKK13   -> 정답

string str;
string outputStr;
int curNum;
int outputNum = 0;

int main()
{
    cin >> str;
    
    for (int i = 0; i < str.size(); i++)
    {
        curNum = str[i] - '0';
        if (0 <= curNum && curNum <= 9)
        {
            outputNum += curNum;
        }
        else
        {
            outputStr += str[i];
        }
    }
    
    sort(outputStr.begin(), outputStr.end());
    
    cout << outputStr << outputNum << '\n';
}
