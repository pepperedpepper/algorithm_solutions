#include <iostream>
#include <vector>
using namespace std;

// 1.5 One Away:
// There are three types of edits that can be performed on strings:
// insert a character, remove a character, or replace a character.
// Given two strings, write a function to check if they are one edit (or zero edits) away

bool oneEditAway(const string& a, const string& b)
{
    int aSize = a.size();
    int bSize = b.size();
    int diffSize = a.size() - b.size();
    if (diffSize >= 2 || diffSize <= -2) return false;
    
    int ai = 0, bi = 0;
    int diffCount = 0;
    
    while(1)
    {
        if (aSize <= ai || bSize <= bi)
        {
            if (ai != aSize || bi != bSize) diffCount++;
            break;
        }
        
        if (a[ai] == b[bi])
        {
            ai++;
            bi++;
            continue;
        }
        
        diffCount++;
        if (diffCount > 1) return false;
        
        ai = (aSize < bSize) ? ai : ai + 1;
        bi = (bSize < aSize) ? bi : bi + 1;
    }
    
    return diffCount <= 1;
}


int main()
{
    string a = "ple";
    string b = "pale";
    
    cout << ((oneEditAway(a, b) == true) ? "TRUE" : "FALSE") << endl;
}
