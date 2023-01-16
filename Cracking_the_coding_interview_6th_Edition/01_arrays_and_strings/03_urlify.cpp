#include <iostream>
#include <vector>
using namespace std;

// 1.3 URLify:
// Write a method to replace all spaces in a string with '%20'.
// You may assume that the string has sufficient space at the end to hold the additional characters,
// and that you are given the "true" length of the string.

string urlify(string& str)
{
    long totSize = str.size();
    for (int i = 0; i < str.size(); i++)
        if (str[i] == ' ')
            totSize += 3;
    
    string result;
    result.resize(totSize);
            
    int idx = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            result[idx++] = '%';
            result[idx++] = '2';
            result[idx++] = '0';
            continue;
        }
        
        result[idx++] = str[i];
    }
    
    return result;
}

int main()
{
    string str = "I have a dream.";
    
    cout << urlify(str) << endl;
}
