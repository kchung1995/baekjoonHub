// 문제 링크: https://www.acmicpc.net/problem/19637
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
vector<pair<pair<int, int>, string> > ranks;

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	
	int to;
	string rankName;
	cin >> rankName >> to;
	ranks.push_back({ {0, to}, rankName });

	for (int i = 1; i < n; i++) {
		cin >> rankName >> to;
		ranks.push_back({ {ranks[i - 1].first.second, to}, rankName});
	}
}

string binarySearch(int level) {
	int left = 0, right = n - 1;

	int mid;

	while (left <= right) {
		mid = (left + right) / 2;

		// 만약 선택된 구간에 level이 들어가 있다면
		if (ranks[mid].first.first < level && level <= ranks[mid].first.second) {
			return ranks[mid].second;
		}
		// 만약 구간이 level보다 더 크다면
		else if (ranks[mid].first.first >= level) {
			right = mid - 1;
		}
		else if (ranks[mid].first.second < level) {
			left = mid + 1;
		}
	}

	return ranks[mid].second;
}

void simulate() {
	for (int i = 0; i < m; i++) {
		// 각 캐릭터의 전투력 수치를 입력받는다.
		int level; cin >> level;

		// 해당 캐릭터의 전투력 수치를 포함하는 구간을 이분 탐색으로 찾는다.
		cout << binarySearch(level) << '\n';
	}
}

int main() {
	init();
	simulate();
	return 0;
}