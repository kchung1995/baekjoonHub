// 문제 링크: https://www.acmicpc.net/problem/22866
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int n;
vector<int> buildings;
vector<int> bldgCount;
vector<int> closestBldg;

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		buildings.push_back(temp);
	}
}

void viewLeft() {
	stack<pair<int, int> > s;	// 빌딩 높이, 빌딩 번호
	
	for (int i = 0; i < n; i++) {
		// 스택이 비었다면, 왼쪽에는 현재 건물보다 더 높은 건물이 없다는 뜻이다.
		if (s.empty()) {
			bldgCount.push_back(0);
			closestBldg.push_back(-1);
			s.push({ buildings[i], i });
		}
		else {
			// 현재 건물보다 더 높은 건물이 나올 때까지 찾는다.
			while (s.top().first <= buildings[i]) {
				s.pop();
				if (s.empty()) break;
			}
			if (s.empty()) {	// 그런 건물이 없다면
				bldgCount.push_back(0);
				closestBldg.push_back(-1);
			}
			else {	// 그런 건물이 있다면
				bldgCount.push_back(s.size());
				closestBldg.push_back(s.top().second);
			}
			s.push({ buildings[i], i });
		}
	}
}

void viewRight() {
	stack<pair<int, int> > s;	// 빌딩 높이, 빌딩 번호

	for (int i = n - 1; i >= 0; i--) {
		// 스택이 비었다면, 오른쪽에는 현재 건물보다 더 높은 건물이 없다는 뜻이다.
		if (s.empty()) {
			// bldgCount[i] += 0;
			s.push({ buildings[i], i });
		}
		else {
			// 현재 건물보다 더 높은 건물이 나올 때까지 찾는다.
			while (s.top().first <= buildings[i]) {
				s.pop();
				if (s.empty()) break;
			}
			if (s.empty()) {	// 그런 건물이 없다면
				// bldgCount[i] += 0;
				s.push({ buildings[i], i });
			}
			else {	// 그런 건물이 있다면
				bldgCount[i] += s.size();
				
				// 만약 왼쪽에서 더 높은 건물을 못 찾았다면, 무조건 오른쪽 건물 중 가장 가까운 건물을 넣는다.
				if (closestBldg[i] == -1) {
					closestBldg[i] = s.top().second;
				}
				// 만약 왼쪽에서 더 높은 건물을 찾았다면, 오른쪽 건물의 거리가 더 가깝다면 갱신한다.
				else if (abs(s.top().second - i) < abs(closestBldg[i] - i)) {
					closestBldg[i] = s.top().second;
				}
				s.push({ buildings[i], i });
			}
		}
	}
}

void printResult() {
	for (int i = 0; i < n; i++) {
		cout << bldgCount[i] << ' ';
		if (bldgCount[i] != 0) {
			cout << closestBldg[i] + 1;
		}
		cout << '\n';
	}
}

int main() {
	init();
	viewLeft();
	viewRight();
	printResult();
	return 0;
}