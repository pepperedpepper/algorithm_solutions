#include <iostream>
using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/42889

// 실패율 = 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어의 수
// 스테이지에 도달한 플레이어가 없다면 실패율은 0이다.
// 만약 실패율이 같다면, 스테이지 번호가 작은 것이 먼저오도록 한다.

// 입력:  5                         -> 전체 스테이지 수 n (1 <= n <= 500)
//       2, 1, 2, 6, 2, 4, 3, 3    -> 게임 사용자가 현재 도전 중인 스테이지 번호들. n + 1은 모두 클리어를 의미한다.
// 출력:  3 4 2 1 5                 -> 실패율이 높은 스테이지부터 내림차순으로 출력

// 입력:  4
//       4, 4, 4, 4, 4
// 출력:  4 1 2 3


vector<int> solution(int stageCount, vector<int> playingStages)
{
    vector<pair<int, double>> fails;
    vector<int> resultStages;
    int length = (int)playingStages.size();
    
    for (int stage = 1; stage <= stageCount; stage++)
    {
        int cnt = count(playingStages.begin(), playingStages.end(), stage);

        double fail = 0;
        if (length >= 1) fail = (double)cnt / length;

        fails.push_back({ stage, fail });
        length -= cnt;
    }
    
    sort(fails.begin(), fails.end(), [](const pair<int, double>& a, const pair<int, double>& b)
    {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });
    
    for (int i = 0; i < stageCount; i++)
        resultStages.push_back(fails[i].first);
    
    return resultStages;
}


int main()
{
    int stageCount = 5;
    vector<int> playingStages = { 2, 1, 2, 6, 2, 4, 3, 3  };
    
    vector<int> result = solution(stageCount, playingStages);
    
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';
    cout << '\n';
}
