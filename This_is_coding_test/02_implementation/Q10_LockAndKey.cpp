#include <iostream>
using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/60059

// n X n 크기의 자물쇠가 있고, m X m 크기의 열쇠가 있다.
// 둘 다 모두 홈과 돌기가 있는데, 열쇠를 회전이나 이동시켜서 자물쇠의 홈을 모두 채워야 열린다.
// 2차원 배열로 주어졌을 때 열 수 있는 지 없는지를 리턴하라.

// 입력:  {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}   -> 열쇠
//       {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}}   -> 자물쇠
// 결과:  true

enum { IN, OUT };
int keySize, lockSize;

bool isLockFilled(const vector<vector<int>>& key, const vector<vector<int>>& lock, const int& moveX, const int& moveY)
{
    // lock을 순회하며 채웠는지 확인
    for (int ly = 0; ly < lockSize; ly++)
    {
        for (int lx = 0; lx < lockSize; lx++)
        {
            int curLock = lock[ly][lx];
            
            int curKeyX = lx + moveX;
            int curKeyY = ly + moveY;
            
            // key가 존재하지 않는 위치
            if (curKeyX < 0 || curKeyY < 0 || keySize <= curKeyX || keySize <= curKeyY)
            {
                // lock의 홈이 안 채워지면 실패.
                if (curLock == IN) return false;
            }
            // key가 존재하는 위치
            else
            {
                int curKey = key[curKeyY][curKeyX];
                
                // lock과 key가 같으면 실패.
                if (curLock == curKey) return false;
            }
        }
    }
    
    return true;
}

bool moveKeyThenCheckLockFilled(const vector<vector<int>>& key, const vector<vector<int>>& lock)
{
    // 키 옮기기. KeySize가 3이면 gap( 2 ~ -2 )범위로 움직인다.
    int gap = keySize - 1;
    
    for (int moveY = gap; moveY >= -gap; moveY--)
    {
        for (int moveX = gap; moveX >= -gap; moveX--)
        {
            bool isFilled = isLockFilled(key, lock, moveX, moveY);
            
            if (isFilled == true) return true;
        }
    }
    
    return false;
}

void turnKey(const vector<vector<int>>& key, vector<vector<int>>& turnedKey)
{
    for (int y = 0; y < keySize; y++)
        for (int x = 0; x < keySize; x++)
            turnedKey[x][keySize - y - 1] = key[y][x];
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    keySize = (int)key.size();
    lockSize = (int)lock.size();
    vector<vector<int>> turnedKey = key;
    
    for (int turn = 0; turn < 4; turn++)
    {
        bool isFilled = moveKeyThenCheckLockFilled(turnedKey, lock);
        
        if (isFilled == true) return true;
        if (turn == 3) break;
        
        turnKey(key, turnedKey);
        key = turnedKey;
    }
    
    return false;
}

int main()
{
    vector<vector<int>> key = { {0, 0, 0}, {1, 0, 0}, {0, 1, 1} };
    vector<vector<int>> lock = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };

    bool answer = solution(key, lock);
    
    cout << answer << '\n';
}
