// 문제 번호: https://www.acmicpc.net/problem/2467
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<int> d;

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		d.push_back(temp);
	}
}

void simulate() {

	int left = 0, right = n - 1;
	// 투 포인터 사용
	// 숫자를 오름차순으로 쭉 정렬한다.
	

	sort(d.begin(), d.end());

	int smallest = 2147483647;
	int smallLeft = -1, smallRight = 01;
	while (left < right) {
		bool isNegative = false;
		int temp = d[left] + d[right];
		if (temp == 0) {
			smallLeft = left;
			smallRight = right;
			break;
		}

		if (temp > 0) isNegative = false;
		if (temp < 0) isNegative = true;
		temp = abs(temp);

		if (temp < smallest) {
			smallLeft = left;
			smallRight = right;
			smallest = temp;
		}
		if (isNegative) {
			left++;
		}
		else {
			right--;
		}
	}

	cout << d[smallLeft] << ' ' << d[smallRight];
}

int main() {
	init();
	simulate();
	return 0;
}