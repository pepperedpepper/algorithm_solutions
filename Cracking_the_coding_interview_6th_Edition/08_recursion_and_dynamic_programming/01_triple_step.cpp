#include <iostream>
#include <vector>
using namespace std;

// 8.1 Triple Step:
// A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time,
// implement a method to count how many possible ways the child can run up the stairs.


int countWays(int stepMax, vector<int>& steps)
{
    if (stepMax <= 0) return 1;
    
    int sum = 0;
    for (int i = 0; i < steps.size(); i++)
    {
        if (stepMax - steps[i] < 0) continue;
        sum += countWays(stepMax - steps[i], steps);
    }
    
    return sum;
}


int main()
{
    int stepMax = 6;
    
    vector<int> steps;
    steps.push_back(1);
    steps.push_back(2);
    steps.push_back(3);
    
    cout << countWays(stepMax, steps) << endl;
}
