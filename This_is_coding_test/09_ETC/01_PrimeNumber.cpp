#include <iostream>
using namespace std;

// 소수: 2보다 큰 자연수 중에서, 1과 자기 자신 말고는 약수가 없는 수.
// 약수: 어떤 수를 나누어 떨어지게 하는 수.

// 소수가 아닌 경우, 가운데 위치한 약수를 중심으로 대칭적으로 약수가 형성된다.
// 예를 들어, 16의 경우 = 1 2 4 8 16 이므로 4를 중심으로 대칭적으로 약수가 형성됨을 알 수 있다.

// 따라서 '어떤 수의 제곱근까지만 약수인지 판별'하면 된다.

bool IsPrimeNumber(int num)
{
    int sqrtNum = sqrt(num);
    
    for (int i = 2; i <= sqrtNum; i++)
        if (num % i == 0) return false;
    
    return true;
}


// 에라토스테네스의 체: <= N 의 소수를 모두 찾을 때 사용 할 수 있다.

// 1) 2부터 N의 제곱근까지의 수 중에서, 아직 처리하지 않은 가장 작은 수를 선택한다.
// 2) 그 수의 배수를 모두 제거한다 (그 수는 제거하면 안 됨)

const int NUMBER_MAX = 100;
bool isPrime[NUMBER_MAX];

void FindPrimeNumbers(int num)
{
    fill(isPrime, isPrime + NUMBER_MAX, true);
    
    int sqrtNum = sqrt(num);
    
    for (int x = 2; x <= sqrtNum; x++)
    {
        if (isPrime[x] == true)
        {
            for (int i = 2; i <= num / x; i++)
                isPrime[x * i] = false;
        }
    }
    
    // (출력)
    for (int x = 2; x <= num; x++)
        if (isPrime[x] == true)
            cout << x << ' ';
    cout << '\n';
}

int main()
{
    int num;
    cin >> num;
    
    cout << IsPrimeNumber(num) << '\n';
    
    FindPrimeNumbers(num);
}
