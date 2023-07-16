#include <iostream>
using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/60058

// 작성된 괄호가 개수는 맞지만 짝이 안 맞아서 오류가 난다.

// 개수가 맞지만 짝이 안 맞는 문자열(=균형잡힌 괄호 문자열)은 다음 과정을 통해 올바를 문자열로 만들 수 있다.

//    1. 입력이 빈 문자열인 경우, 빈 문자열을 반환한다.
//    2. 문자열 w를 두 균형잡힌 괄호 문자열 u, v로 분리한다.
//       단, u는 균형잡힌 괄호 문자열로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있다.
//    3. 문자열 u가 올바른 괄호 문자열이라면 문자열 v에 대해 1단계부터 다시 수행한다.
//       그리고 수행한 결과 문자열을 u에 이어붙인 후 반환한다.
//    4. 문자열 u가 올바른 괄호 문자열이 아니라면 다음 과정을 수행한다.
//       4-1. 빈 문자열에 첫 번째 문자로 (를 붙인다.
//       4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙인다.
//       4-3. )를 다시 붙인다.
//       4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙인다.
//       4-5. 생성된 문자열을 반환한다.


bool isRightString(string str)
{
    int cntLeft = 0, cntRight = 0;
    for (int i = 0; i < str.size(); i++)
    {
        (str[i] == '(' ? cntLeft : cntRight)++;
        if (cntLeft < cntRight) return false;
    }
    
    return true;
}

string DFS(string str)
{
    if (str.empty() == true) return "";
    
    // u, v 만들기
    bool uCompleted = false;
    int cntLeft = 0, cntRight = 0;
    string u, v;
    for (int i = 0; i < str.size(); i++)
    {
        (uCompleted == false ? u : v) += str[i];
        
        (str[i] == '(' ? cntLeft : cntRight)++;
        if (cntLeft == cntRight) uCompleted = true;
    }
    
    if (isRightString(u))
    {
        string resultV = DFS(v);
        return u + resultV;
    }
    else
    {
        string result = "(";
        result += DFS(v);
        result += ')';
        
        for (int i = 1; i < u.size() - 1; i++)
            result += (u[i] == ')' ? '(' : ')');
        
        return result;
    }
}


string solution(string str)
{
    return DFS(str);
}

int main()
{
    string s1 = "(()())()";   // -> (()())()
    string s2 = ")(";         // -> ()
    string s3 = "()))((()";   // -> ()(())()

    cout << solution(s1) << endl;
}
