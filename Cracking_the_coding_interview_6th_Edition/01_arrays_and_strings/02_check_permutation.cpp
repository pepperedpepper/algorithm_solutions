#include <iostream>
#include <vector>
using namespace std;

// 1.2 Check Permutation:
// Given two strings, write a method to decide if one is a permutation of the other.

bool arePermutation(string& a, string& b)
{
    long aSize = a.size();
    long bSize = b.size();
    if (aSize != bSize) return false;
    
    vector<int> counter(128);
    
    for (int i = 0; i < aSize; i++)
        counter[a[i]]++;
    
    for (int i = 0; i < bSize; i++)
    {
        counter[b[i]]--;
        if (counter[b[i]] < 0) return false;
    }
    
    return true;
}

int main()
{
    string a = "abaa";
    string b = "aaab";
    
    cout << ((arePermutation(a, b) == true) ? "TRUE" : "FALSE") << endl;
}
