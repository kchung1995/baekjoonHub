// 문제 링크: https://www.acmicpc.net/problem/2581
#include <iostream>
using namespace std;
#define MAX_N 10001

bool isPrimeNumber[MAX_N];
int m, n;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i < MAX_N; i++) {
        isPrimeNumber[i] = true;
    }
}

void managePrime() {
    isPrimeNumber[1] = false;
    for (int i = 2; i < MAX_N; i++) {
        if (isPrimeNumber[i]) {
            for (int j = i*2; j < MAX_N; j+=i) {
                isPrimeNumber[j] = false;
            }
        }
    }
}

void solution() {
    int minPrime = -1;
    int sum = 0;
    for (int i = m; i <= n; i++) {
        if (isPrimeNumber[i]) {
            if (minPrime == -1) {
                minPrime = i;
            }
            sum += i;
        }
    }
    
    if (sum == 0) {
        cout << -1;
        return;
    }
    cout << sum << '\n' << minPrime;
}

int main() {
    init();
    managePrime();
    solution();
    return 0;
}
