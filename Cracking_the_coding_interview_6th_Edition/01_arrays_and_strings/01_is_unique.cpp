#include <iostream>
#include <vector>
using namespace std;

// 1.1 Is Unique:
// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?

bool isUnique(string& str)
{
    if (128 < str.size()) return false;
    
    vector<bool> visited(128);
    
    for (int i = 0; i < str.size(); i++)
    {
        int curIndex = str[i];
        if (visited[curIndex] == true) return false;
        visited[curIndex] = true;
    }
    
    return true;
}

int main()
{
    string str = "hello";
    
    cout << ((isUnique(str) == true) ? "TRUE" : "FALSE") << endl;
}
