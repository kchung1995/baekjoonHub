// 문제 링크: https://www.acmicpc.net/problem/15486
#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 1500001

int n;
int dp[MAX_N];
int schedules[MAX_N][2];     // 각 상담 기간, 금액

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t, p; cin >> t >> p;
        schedules[i][0] = t;
        schedules[i][1] = p;
    }
}

int solution() {
    int result = -1;
    
    for (int i = 0; i <= n; i++) {
        result = max(result, dp[i]);
        
        if (i + schedules[i][0] > n + 1) continue;
        dp[i + schedules[i][0]] = max(result + schedules[i][1], dp[i + schedules[i][0]]);
    }
    
    return result;
}

int main() {
    init();
    cout << solution();
    return 0;
}
