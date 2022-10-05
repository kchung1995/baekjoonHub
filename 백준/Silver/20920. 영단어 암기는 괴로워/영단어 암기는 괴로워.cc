// 문제 링크: https://www.acmicpc.net/problem/20920
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int n, m;
unordered_set<string> words;
unordered_map<string, int> wordCount;
vector<pair<string, int> > result;

bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second) {
		if (a.first.size() == b.first.size()) {
			return a.first < b.first;
		}
		return a.first.size() > b.first.size();
	}
	return a.second > b.second;
}

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		if (temp.size() >= m) {
			words.insert(temp);
			if (wordCount.find(temp) == wordCount.end()) {
				wordCount.insert({ temp, 1 });
			}
			else {
				wordCount[temp]++;
			}
		}
	}
}

void simulate() {
	
	for (auto &next : words) {
		result.push_back({ next, wordCount[next] });
	}

	sort(result.begin(), result.end(), cmp);

	for (auto& next : result) {
		cout << next.first << '\n';
	}

}

int main() {
	init();
	simulate();
	return 0;
}