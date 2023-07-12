#include <iostream>
using namespace std;

// 행의 가장 작은 수만 선택할 수 있을 때, 가장 큰수를 선택할 수 있는 행은?

// 입력:  3 3     <- 행의 개수, 열의 개수
//       3 1 2    <- 카드
//       4 1 4
//       2 2 2
// 출력:  2       <- 선택한 가장 큰 수

// 입력:   2 4
//        7 3 1 8
//        3 3 3 4
// 출력:   3

const int CARD_NUMBER_MAX = 10001;
const int CARD_LINE_MAX = 100;
int cards[CARD_LINE_MAX][CARD_LINE_MAX];
int row, col, pickedCard = 0;

void PickMaxCard()
{
    for (int i = 0; i < row; i++)
    {
        int colMinCard = CARD_NUMBER_MAX;
        
        for (int j = 0; j < col; j++)
            if (cards[i][j] < colMinCard)
                colMinCard = cards[i][j];
        
        if (pickedCard < colMinCard)
            pickedCard = colMinCard;
    }
}

int main()
{
    cin >> row >> col;
    
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> cards[i][j];
    
    PickMaxCard();
    
    cout << pickedCard << '\n';
}
