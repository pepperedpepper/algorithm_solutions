#include <iostream>
using namespace std;

// n명의 학생정보(이름, 성적)에서 성적이 낮은 순서대로 이름을 출력하라.

// 입력:  2           -> 학생 수 n
//       홍길동 95     -> 학생 정보
//       이순신 77
// 출력:  이순신 홍길동   -> 성적 오름차순 정렬 결과

struct Student
{
    string name;
    int score;
};

const int STUDENT_COUNT_MAX = 100000;
Student students[STUDENT_COUNT_MAX];
int studentCount;
string inputName;
int inputScore;

int main()
{
    cin >> studentCount;
    
    for (int i = 0; i < studentCount; i++)
    {
        cin >> inputName >> inputScore;
        
        students[i].name = inputName;
        students[i].score = inputScore;
    }
    
    sort(students, students + studentCount, [](const Student& a, const Student& b){ return a.score < b.score; });
    
    for (int i = 0; i < studentCount; i++)
        cout << students[i].name << ' ';
    cout << '\n';
}
