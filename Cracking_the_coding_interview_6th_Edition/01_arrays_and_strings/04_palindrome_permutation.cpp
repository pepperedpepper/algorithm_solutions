#include <iostream>
#include <vector>
using namespace std;

// 1.4 Palindrome Permutation:
// Given a string, write a function to check if it is a permutation of a palindrome.
// A palindrome is a word or phrase that is the same forwards and backwards.
// A permutation is a rearrangement of letters.
// The palindrome does not need to be limited to just dictionary words.

bool isPermutationOfPalindrome(string& str)
{
    auto size = str.size();
    
    vector<int> count(128);
    int oddCount = 0;
    for (int i = 0; i < size; i++)
    {
        count[str[i]]++;
        
        if (count[str[i]] % 2 == 0) oddCount--;
        else                        oddCount++;
    }
    
    bool isEven = size % 2 == 0;
    if (isEven == true  && oddCount > 0) return false;
    if (isEven == false && oddCount > 1) return false;
    
    return true;
}

int main()
{
    string str = "rats live on no evil star";
    
    cout << ((isPermutationOfPalindrome(str) == true) ? "TRUE" : "FALSE") << endl;
}
