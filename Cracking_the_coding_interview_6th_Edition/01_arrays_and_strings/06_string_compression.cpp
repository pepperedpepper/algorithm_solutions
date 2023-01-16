#include <iostream>
#include <vector>
using namespace std;

// 1.6 String Compression:
// Implement a method to perform basic string compression using the counts of repeated characters.
// For example, the string aabcccccaaa would become a2b1c5a3,
// If the "compressed" string would not become smaller than the original string,
// your method should return the original string.
// You can assume the string has only uppercase and lowercase letters (a - z).

string compressString(const string& str)
{
    string result;
    
    size_t size = str.size();
    if (size < 2) return str;
    
    int i = 1;
    int count = 1;
    
    while(i < size)
    {
        if (str[i - 1] != str[i])
        {
            result += str[i - 1];
            result += (count + '0');
            
            if (size <= result.size()) return str;
            
            count = 1;
        }
        else
        {
            count++;
        }
        
        i++;
    }
    
    result += str[i - 1];
    result += (count + '0');
    
    return (size <= result.size()) ? str : result;
}


int main()
{
    string str = "aabcccccaaa";
    
    cout << compressString(str) << endl;
}
