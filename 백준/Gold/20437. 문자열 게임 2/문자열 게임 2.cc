// 문제 링크: https://www.acmicpc.net/problem/20437
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int t;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
}

void simulate() {
    string temp;
    int k;
    cin >> temp >> k;
    
    // 각 문자가 등장하는 위치를 기록
    vector<vector<int> > charPos(26);
    for (int i = 0; i < temp.size(); i++) {
        charPos[temp[i] - 'a'].push_back(i);
    }
    
    int minLength = 1e9, maxLength = 0;
    for (vector<int> &next : charPos) {
        if (next.size() < k) continue;
        for (int i = 0; i <= next.size() - k; i++) {
            minLength = min(minLength, next[i + k - 1] - next[i] + 1);
            maxLength = max(maxLength, next[i + k - 1] - next[i] + 1);
        }
    }
    
    if (minLength == 1e9 && maxLength == 0) {
        cout << -1 << '\n';
    }
    else {
        cout << minLength << ' ' << maxLength << '\n';
    }
}

int main() {
    init();
    while(t--) {
        simulate();
    }
    return 0;
}
