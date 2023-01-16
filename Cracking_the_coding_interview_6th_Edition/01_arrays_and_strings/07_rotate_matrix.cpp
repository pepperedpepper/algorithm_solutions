#include <iostream>
#include <vector>
using namespace std;

// 1.7 Rotate Matrix:
// Given an image represented by an NxN matrix,
// where each pixel in the image is 4 bytes,
// write a method to rotate the image by 90 degrees.
// Can you do this in place?

void printMatrix(const vector<vector<int>>& matrix, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", matrix[i][j]);
        cout << endl;
    }
    cout << endl;
}

void rotateRight(vector<vector<int>>& matrix, int N)
{
    for (int depth = 0; depth < N / 2; depth++)
    {
        int first = depth;
        int last = N - 1 - depth;
        
        for (int i = 0; i < last - first; i++)
        {
            int temp                 = matrix[first][first + i]; // temp = 위
            matrix[first][first + i] = matrix[last - i][first];  // 위   = 왼쪽
            matrix[last - i][first]  = matrix[last][last - i];   // 왼쪽  = 아래
            matrix[last][last - i]   = matrix[first + i][last];  // 아래  = 오른쪽
            matrix[first + i][last]  = temp;                     // 오른쪽 = 위
        }
    }
}


int main()
{
    int N = 5;
    
    vector<vector<int>> matrix =
    {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    
    cout << "Before : " << endl;
    printMatrix(matrix, N);

    cout << "After : " << endl;
    rotateRight(matrix, N);
    printMatrix(matrix, N);

}
