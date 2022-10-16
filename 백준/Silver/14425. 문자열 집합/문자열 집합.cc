// 문제 링크: https://www.acmicpc.net/problem/14425
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int n, m;
unordered_set<string> dict;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string temp; cin >> temp;
        dict.insert(temp);
    }
}

int simulate() {
    int answer = 0;
    for (int i = 0; i < m; i++) {
        string temp; cin >> temp;
        if (dict.find(temp) != dict.end()) answer++;
    }
    
    return answer;
}

int main() {
    init();
    cout << simulate();
    return 0;
}
