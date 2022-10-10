// 문제 링크: https://www.acmicpc.net/problem/1027
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> buildings;

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		buildings.push_back(temp);
	}
}

int simulate() {

	vector<int> count(n);

	for (int i = 0; i < n; i++) {
		double maxGradient = -1e9;

		for (int j = i + 1; j < n; j++) {
			int dy = buildings[j] - buildings[i];
			int dx = j - i;
			
			double gradient = (dy * 1.0) / dx;

			if (gradient <= maxGradient) continue;

			maxGradient = gradient;
			count[i]++;
			count[j]++;
		}
	}

	sort(count.begin(), count.end());
	return count.back();
}

int main() {
	init();
	cout << simulate();
	return 0;
}