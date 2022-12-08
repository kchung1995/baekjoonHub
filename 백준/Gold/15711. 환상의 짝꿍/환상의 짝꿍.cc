// 문제 링크: https://www.acmicpc.net/problem/15711
#include <iostream>
#include <vector>
using namespace std;
#define MAX_A 2000001
#define MAX_B 2000000

int t;
const string yes = "YES";
const string no = "NO";
vector<int> primes;

void eratosthenes() {
    bool primeCheck[MAX_A] = {false, };
    primeCheck[1] = true;
    for (int i = 2; i * i < MAX_B; i++) {
        if (!primeCheck[i]) {
            for (int j = i * i; j < MAX_B; j += i) {
                primeCheck[j] = true;
            }
        }
    }
    
    for (int i = 2; i < MAX_A; i++) {
        if (!primeCheck[i]) {
            primes.push_back(i);
        }
    }
}

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    eratosthenes();
}

string simulate() {
    long long a, b;
    cin >> a >> b;
    long long sum = a + b;
    
    if (sum == 2 || sum == 3) {
        return no;
    }
    if (sum % 2 == 0) { // 골드바흐의 추측
        return yes;
    }
    
    sum -= 2;
    for (auto &next : primes) {
        if ((long long)(next * next) > sum) {
            break;
        }
        if (sum % next == 0) {
            return no;
        }
    }
    return yes;
}

int main() {
    init();
    while(t--) {
        cout << simulate() << '\n';
    }
    return 0;
}
