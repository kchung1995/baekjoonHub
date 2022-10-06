// 문제 링크: https://www.acmicpc.net/problem/2164
#include <iostream>
#include <queue>

using namespace std;

int n;
queue<int> q;

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
}

int simulate() {
	
	while (1) {
		// 원소가 한개 뿐이라면 게임 끝.
		if (q.size() == 1) {
			return q.front();
		}
		q.pop();	// 카드를 한장 버린다.
		if (q.size() == 1) {	// 버리고 나서 카드가 하나만 남는다면
			return q.front();
		}
		// 그렇지 않다면 가장 위의 카드를 가장 아래로 보낸다.
		q.push(q.front());
		q.pop();
	}

	return q.front();
}

int main() {
	init();
	cout << simulate();
	return 0;
}