#include <iostream>
#include <vector>
using namespace std;

// 정렬 기준
//     1. 국어 점수가 감소하는 순서
//     2. 국어 점수가 같으면 영어 점수가 증가하는 순서
//     3. 국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서
//     4. 모든 점수가 같으면 이름이 사전 순으로 증가하는 순서 (대문자가 소문자보다 앞에 온다 - 아스키 코드)

// 입력:  12                  <- 학생 수 n
//       Junkyu 50 60 100    <- 이름, 국어, 영어, 수학점수
//       Sangkeun 80 60 50
//       Sunyoung 80 70 100
//       Soong 50 60 90
//       Haerim 50 60 100
//       Kangsoo 60 80 100
//       DongHyuk 80 60 100
//       Sei 70 70 70
//       Wonseob 70 70 90
//       Sanghyun 70 70 80
//       nsj 80 80 80
//       Taswhan 50 60 90
// 출력:  Donghyuk            <- 정렬 결과
//       Sangkeun
//       Sunyoung
//       nsj
//       Wonseob
//       Sanghyun
//       Sei
//       Kangsoo
//       Haerim
//       Junkyu
//       Soong
//       Taewhan

struct Student
{
    string name;
    int korean;
    int english;
    int math;
    
    Student(string name, int kor, int eng, int m)
    {
        this->name = name;
        this->korean = kor;
        this->english = eng;
        this->math = m;
    }

    bool operator<(const Student& s) const
    {
        if (korean != s.korean)        return korean > s.korean;
        else if (english != s.english) return english < s.english;
        else if (math != s.math)       return math > s.math;
        return name < s.name;
    }
};


vector<Student> students;
int studentCount, ko, en, math;
string name;

int main()
{
    cin >> studentCount;
    
    for (int i = 0; i < studentCount; i++)
    {
        cin >> name >> ko >> en >> math;
        students.push_back(Student(name, ko, en, math));
    }
    
    sort(students.begin(), students.end());
    
    for (int i = 0; i < studentCount; i++)
        cout << students[i].name << '\n';
}
