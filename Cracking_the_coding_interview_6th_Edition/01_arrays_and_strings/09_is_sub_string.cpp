#include <iostream>
#include <vector>
using namespace std;

// 1.9 String Rotation:
// Assume you have a method isSubstring which checks if one word is a substring of another.
// Given two strings, s1 and s2,
// write code to check if s2 is a rotation of s1 using only one call to isSubstring
// [e.g., "waterbottle " is a rotation of 'erbottlewat"),


bool isSubString(string& src, string& rot)
{
    size_t srcSize = src.size();
    size_t rotSize = rot.size();
    if (srcSize != rotSize || srcSize == 0) return false;
    
    string srcTwice = src + src;
    
    return srcTwice.find(rot) != string::npos;
}

int main()
{
    string src = "erbottlewat";
    string rot = "waterbottle";
    
    cout << ((isSubString(src, rot) == true) ? "TRUE" : "FALSE") << endl;
}
