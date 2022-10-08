// 문제 링크: https://www.acmicpc.net/problem/20922
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_E 100001

int n, k;
vector<int> sequence;
int cnt[100001] = { 0, };

void init() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		sequence.push_back(temp);
	}
}

int simulate() {

	int answer = 0;
	int start = 0;

	for (int i = 0; i < n; i++) {

		// 먼저 현재 수를 센다.
		cnt[sequence[i]]++;
		//arr[i]를 수열에 포함시켰는데 arr[i]의 빈도수가 k보다 큰 경우 start 증가
		while (cnt[sequence[i]] > k) {
			cnt[sequence[start++]]--;
		}
		answer = max(answer, i - start + 1);
	}
	
	return answer;
}

int main() {

	init();
	cout << simulate();

	return 0;
}