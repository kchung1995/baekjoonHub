// 문제 링크: https://www.acmicpc.net/problem/15989
#include <iostream>
using namespace std;

#define MAX_N 10001

int dp[MAX_N][4] = { 0, };
int n;

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
}

void dynamic() {

	// 순서만 다른 수식은 같은 수식으로 친다.
	// 따라서 맨 마지막에 1이 오면, 그 이전에 1만 올 수 있다.
	// 맨 마지막에 2가 오면, 그 이전에 1, 2만 올 수 있다.
	// 맨 마지막에 3이 오면, 그 이전에 1, 2, 3이 올 수 있다.
	dp[0][1] = 1;
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 2;

	for (int i = 2; i < MAX_N; i++) {
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
	}
}

void simulate() {
	while (n--) {
		int temp;
		cin >> temp;
		cout << dp[temp][1] + dp[temp][2] + dp[temp][3] << '\n';
	}
}

int main() {
	init();
	dynamic();
	simulate();
	return 0;
}