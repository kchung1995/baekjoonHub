// 문제 링크: https://www.acmicpc.net/problem/5597
#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> submitted;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 28; i++) {
        int temp; cin >> temp;
        submitted.insert(temp);
    }
}

void solution() {
    for (int i = 1; i <= 30; i++) {
        if (submitted.find(i) == submitted.end()) {
            cout << i << '\n';
        }
    }
    return;
}

int main() {
    init();
    solution();
    return 0;
}
