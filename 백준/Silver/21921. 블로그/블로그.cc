// 문제 링크: https://www.acmicpc.net/problem/21921
#include <iostream>
#include <vector>
using namespace std;

int n, x;
int views[250000];

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> views[i];
	}
}

void simulate() {
	int viewMax = 0;
	int sum = 0;
	int viewMaxCount = 1;

	// 맨 앞 x일의 누적 조회수를 구한다.
	for (int i = 0; i < x; i++) {
		sum += views[i];
	}
	viewMax = sum;

	// 투포인터를 이용하여 날짜를 하루씩 더하고 빼며 탐색
	for (int i = x; i < n; i++) {
		sum -= views[i - x];
		sum += views[i];

		if (sum > viewMax) {
			viewMax = sum;
			viewMaxCount = 1;
		}
		else if (sum == viewMax) {
			viewMaxCount++;
		}
	}

	// 결과 출력
	if (viewMax == 0) {
		cout << "SAD";
	}
	else {
		cout << viewMax << '\n' << viewMaxCount;
	}
}

int main() {
	init();
	simulate();
	return 0;
}