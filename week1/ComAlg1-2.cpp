#include <iostream>

using namespace std;

const int N = 500;

int main()
{
    int i, j, a[N + 1];
    int cnt = 0;    // 곱셉 연산 횟수 구하기
    int max_prime = 0;
    for (a[1] = 0, i = 2; i <= N; i++)
        a[i] = 1;
    for (i = 2; i <= N / 2; i++)
        for (j = 2; j <= N / i; j++) {
            a[i * j] = 0;
            cnt++;
        }
    for (i = 1; i <= N; i++) {
        if (a[i]) {
            cout << i << ' ';
            max_prime = i;
        }
    }
    cout << "\n";
    cout << "N 보다 작은 최대 소수: " << max_prime << "\n";
    cout << "곱셉 연산 횟수: " << cnt << "\n";
}