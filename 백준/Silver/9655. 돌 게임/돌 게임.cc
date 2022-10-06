// 문제 링크: https://www.acmicpc.net/problem/9655
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1001

int n;
int dp[MAX_N] = { 0, };

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
}

void simulate() {

	// 1, 2는 경우의 수가 하나밖에 존재하지 않는다.
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
	}
}

void printAnswer() {
	if (dp[n] % 2 == 1) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}
}

int main() {
	init();
	simulate();
	printAnswer();
	return 0;
}