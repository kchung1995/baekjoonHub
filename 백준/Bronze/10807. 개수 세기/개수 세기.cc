// 문제 링크: https://www.acmicpc.net/problem/10807
#include <iostream>
#include <unordered_map>
using namespace std;

int n;
unordered_map<int, int> numCount;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        if (numCount.find(temp) == numCount.end()) {
            numCount.insert({temp, 1});
        }
        else {
            numCount[temp]++;
        }
    }
}

int solution() {
    int temp; cin >> temp;
    if (numCount.find(temp) == numCount.end()) {
        return 0;
    }
    return numCount[temp];
}

int main() {
    init();
    cout << solution();
    return 0;
}
