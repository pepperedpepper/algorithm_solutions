#include <iostream>
#include <vector>
using namespace std;

// 1.8 Zero Matrix:
// Write an algorithm such that if an element in an MxN matrix is 0,
// its entire row and column are set to 0.

void nullifyRow(vector<vector<int>>& matrix, int N, int row)
{
    for (int i = 0; i < N; i++)
        matrix[row][i] = 0;
}

void nullifyCol(vector<vector<int>>& matrix, int N, int col)
{
    for (int i = 0; i < N; i++)
        matrix[i][col] = 0;
}

void nullifyMatrix(vector<vector<int>>& matrix, int N)
{
    // 첫번째 행을 열 체크를 위해 사용한다. 
    bool isFirstRowZero = false;
    for (int i = 0; i < N; i++)
    {
        if (matrix[0][i] != 0) continue;
        
        isFirstRowZero = true;
        break;
    }
    
    for (int r = 1; r < N; r++)
    {
        bool isThisRowZero = false;
        for (int c = 0; c < N; c++)
        {
            if (matrix[r][c] != 0) continue;
            
            isThisRowZero = true;
            matrix[0][c] = 0;
        }
        
        if (isThisRowZero) nullifyRow(matrix, N, r);
    }

    for (int i = 0; i < N; i++)
    {
        if (matrix[0][i] != 0) continue;
        
        nullifyCol(matrix, N, i);
    }
    
    if (isFirstRowZero) nullifyRow(matrix, N, 0);
}

void printMatrix(vector<vector<int>>& matrix, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", matrix[i][j]);
        cout << endl;
    }
    cout << endl;
}


int main()
{
    int N = 5;
    
    vector<vector<int>> matrix = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };
    
    nullifyMatrix(matrix, N);
    printMatrix(matrix, N);
}
