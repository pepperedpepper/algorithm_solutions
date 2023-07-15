#include <iostream>
using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/60057

// 압축할 문자열 s가 매개변수로 주어질 때,
// 1개 이상 단위로 문자열을 잘라 압축하여 표현한 문자열 중 가장 짧은 것의 길이를 리턴하라.
// 문자열은 제일 앞부터 정해진 길이만큼 잘라야 한다.

// 입력:  aabbaccc
// 출력:  7         -> 1개 단위로 압축함

// 입력:  ababcdcdababcdcd
// 출력:  9         -> 8개 단위로 압축함

// 입력:  xababcdcdababcdcd
// 출력:  17         -> 압축 안 됨

const int STRING_SIZE_MAX = 1000;
string str;
int strSize;
int minStrLength = STRING_SIZE_MAX;

int main()
{
    cin >> str;
    
    strSize = (int)str.size();
    
    for (int len = 1; len < strSize; len++)
    {
        int sameCounter = 0;
        string prevStr;
        string outputStr;
        
        for (int start = 0; start < strSize; start += len)
        {
            string curStr;
            for (int i = start; i < start + len && i < strSize; i++)
                curStr += str[i];
            
            if (prevStr == curStr)
            {
                sameCounter++;
                
                // 마지막 문자일 경우
                if (strSize <= start + len)
                {
                    outputStr += sameCounter + 1;
                    outputStr += curStr;
                }
            }
            else
            {
                // 이전까지는 같은게 있었다.
                if (0 < sameCounter)
                {
                    outputStr += sameCounter + 1 + '0';
                }
                
                outputStr += prevStr;
                sameCounter = 0;
                
                // 마지막 문자일 경우
                if (strSize <= start + len)
                {
                    outputStr += curStr;
                }
            }
            
            prevStr = curStr;
        }
        
        minStrLength = min(minStrLength, (int)outputStr.size());
    }
    
    cout << minStrLength << '\n';
}
