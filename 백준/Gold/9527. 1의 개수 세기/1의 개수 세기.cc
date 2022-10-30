// 문제 링크: https://www.acmicpc.net/problem/9527
#include <iostream>
using namespace std;
#define MAX_I 55

long long a, b;
long long dp[MAX_I];

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
}

void getDp() {
    dp[0] = 1;
    // 점화식
    for (int i = 1; i < MAX_I; i++) {
        dp[i] = 2 * dp[i-1] + (1LL << i);
    }
}

long long getNumberOfOnes (long long input) {
    long long answer = input & 1;
    
    for (int i = MAX_I - 1; i > 0; i--){
        if (input & (1LL << i)) {
            answer += dp[i - 1] + (input - (1LL << i) + 1);
            input -= (1LL << i);
        }
    }
    return answer;
}

long long solution() {
    return getNumberOfOnes(b) - getNumberOfOnes(a - 1);
}

int main() {
    init();
    getDp();
    cout << solution();
    return 0;
}
