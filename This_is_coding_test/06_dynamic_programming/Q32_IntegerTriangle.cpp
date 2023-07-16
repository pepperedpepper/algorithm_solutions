#include <iostream>
using namespace std;

// 맨 위층 부터 하나씩 수를 선택해서 아래로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구해야 한다.
// 아래층에 있는 수는 대각선 왼쪽 또는 대각선 오른쪽에 있는 것만 선택할 수 있다.

// 입력:    5           -> 삼각형의 층수 n (<= 500)
//         7           -> 정수 삼각형
//         3 8
//         8 1 0
//         2 7 4 4
//         4 5 2 6 5
// 출력:    30          -> 합이 최대가 되는 경로에 있는 수의 합

const int TRIANGLE_SIZE_MAX = 501;
int triangle[TRIANGLE_SIZE_MAX][TRIANGLE_SIZE_MAX];
int triangleSize;

int main()
{
    cin >> triangleSize;
    
    for (int i = 1; i <= triangleSize; i++)
        for (int j = 1; j <= i; j++)
            cin >> triangle[i][j];
    
    for (int i = 2; i <= triangleSize; i++)
        for (int j = 1; j <= i; j++)
            triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);
    
    int maxVal = 0;
    for (int i = 1; i <= triangleSize; i++)
        maxVal = max(maxVal, triangle[triangleSize][i]);

    cout << maxVal << '\n';
}
