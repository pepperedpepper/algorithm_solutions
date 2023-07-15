#include <iostream>
using namespace std;

// 선생님은 학생 n명의 성적을 분실하고, 비교한 결과의 일부만 가지고 있다.
// 각 학생의 성적은 모두 다른데, 이 때 성적 순위를 정확히 알 수 있는 학생은 모두 몇 명인가?

// 입력:  6 6   -> 학생들의 수 n, 두 학생의 성적을 비교한 횟수 m
//       1 5   -> a가 b보다 작다
//       3 4
//       4 2
//       4 6
//       5 2
//       5 4
// 출력:  1     -> 성적 순위를 정확히 알 수 있는 학생의 수

const int INF = 1e9;
const int STUDENT_COUNT_MAX = 501;
int graph[STUDENT_COUNT_MAX][STUDENT_COUNT_MAX];
int studentCount, compareCount, from, to, result = 0;

void Floyd()
{
    for (int k = 1; k <= studentCount; k++)
        for (int a = 1; a <= studentCount; a++)
            for (int b = 1; b <= studentCount; b++)
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
}

int main()
{
    cin >> studentCount >> compareCount;
    
    for (int i = 1; i <= studentCount; i++)
        fill(graph[i], graph[i] + studentCount + 1, INF);
    
    for (int i = 1; i <= studentCount; i++)
        graph[i][i] = 0;
    
    for (int i = 0; i < compareCount; i++)
    {
        cin >> from >> to;
        graph[from][to] = 1;
    }
    
    Floyd();
    
    for (int a = 1; a <= studentCount; a++)
    {
        int count = 0;
        for (int b = 1; b <= studentCount; b++)
        {
            if (graph[a][b] != INF || graph[b][a] != INF)
                count++;
        }
        if (count == studentCount)
            result++;
    }
    
    cout << result << '\n';
}
