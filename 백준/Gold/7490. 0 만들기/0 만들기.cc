// 문제 링크: https://www.acmicpc.net/problem/7490
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int t;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
}

void backtracking(int n, int level, int v, string input, vector<string> &result) {
    if (level == n + 1) {
        if (v == 0) {
            result.push_back(input.substr(1));
        }
        return;
    }
    
    backtracking(n, level + 1, level + v, input + "+" + to_string(level), result);
    if (level < n) {
        backtracking(n,
                     level + 2,
                     v + 10 * level + level + 1,
                     input + "+" + to_string(level) + " " + to_string(level + 1),
                     result
                     );
    }
    if (level == 1) {
        return;
    }
    
    backtracking(n, level + 1, v - level, input + "-" + to_string(level), result);
    if (level < n) {
        backtracking(n,
                     level + 2, v - (10 * level + level + 1),
                     input + "-" + to_string(level) + " " + to_string(level + 1),
                     result);
    }
    return;
}

void solution() {
    int n; cin >> n;
    vector<string> result;
    backtracking(n, 1, 0, "", result);
    sort(result.begin(), result.end());
    for (auto &next : result) {
        cout << next << '\n';
    }
}

int main() {
    init();
    while(t--) {
        solution();
        cout << '\n';
    }
    return 0;
}
