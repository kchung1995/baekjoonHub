// 문제 링크: https://www.acmicpc.net/problem/1992
#include <iostream>
#include <string>
#include <vector>
#define MAX_N 64

using namespace std;
string grid[MAX_N];

int n;

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}
}

string dfs(int x1, int y1, int x2, int y2) {

	// 각 영역이 모두 하나로 이루어져 있다면, 해당 문자열을 리턴
	char temp = grid[x1][y1];
	bool allSame = true;
	string answer = "";
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			if (temp != grid[i][j]) allSame = false;
		}
	}
	if (allSame) {
		answer += string(1, temp);
		return answer;
	}

	// 그렇지 않다면, 재귀함수 호출

	// 주어진 영역을 4등분한다.
	int xmid = (x1 + x2 + 1) / 2;
	int ymid = (y1 + y2 + 1) / 2;

	answer = "(";

	// 왼쪽 위: x1 <= i < xmid, y1 <= j < ymid
	temp = grid[x1][y1];
	allSame = true;
	for (int i = x1; i < xmid; i++) {
		for (int j = y1; j < ymid; j++) {
			if (temp != grid[i][j]) allSame = false;
		}
	}
	if (allSame) {
		answer += string(1, temp);;
	}
	else {
		answer += dfs(x1, y1, xmid, ymid);
	}

	// 오른쪽 위: x1 <= i < xmid, ymid <= j < y2
	temp = grid[x1][ymid];
	allSame = true;
	for (int i = x1; i < xmid; i++) {
		for (int j = ymid; j < y2; j++) {
			if (temp != grid[i][j]) allSame = false;
		}
	}
	if (allSame) {
		answer += string(1, temp);
	}
	else {
		answer += dfs(x1, ymid, xmid, y2);
	}

	// 왼쪽 아래: xmid <= i < x2, y1 <= j < ymid
	temp = grid[xmid][y1];
	allSame = true;
	for (int i = xmid; i < x2; i++) {
		for (int j = y1; j < ymid; j++) {
			if (temp != grid[i][j]) allSame = false;
		}
	}
	if (allSame) {
		answer += string(1, temp);
	}
	else {
		answer += dfs(xmid, y1, x2, ymid);
	}

	// 오른쪽 아래: xmid <= i < x2, ymid <= j < y2
	temp = grid[xmid][ymid];
	allSame = true;
	for (int i = xmid; i < x2; i++) {
		for (int j = ymid; j < y2; j++) {
			if (temp != grid[i][j]) allSame = false;
		}
	}
	if (allSame) {
		answer += string(1, temp);
	}
	else {
		answer += dfs(xmid, ymid, x2, y2);
	}

	answer += ")";
	return answer;
}

int main() {
	init();
	cout << dfs(0, 0, n, n);
	return 0;
}

