// 문제 링크: https://www.acmicpc.net/problem/1927
#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int> q;

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
}

void simulate() {
	int temp;

	while (n--) {
		cin >> temp;
		if (temp == 0) {
			if (q.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << -1 * q.top() << '\n';
				q.pop();
			}
		}
		else {
			q.push(-1 * temp);
		}
	}
}

int main() {
	init();
	simulate();
	return 0;
}