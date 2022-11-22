// 문제 링크: https://www.acmicpc.net/problem/26004
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
string input;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> input;
}

bool inString(char input) {
    if (input == 'H' || input == 'I' || input == 'A' || input == 'R' || input == 'C') {
        return true;
    }
    return false;
}

int simulate() {
    unordered_map<char, int> count;
    
    for (int i = 0; i < n; i++) {
        if (inString(input[i])) {
            count[input[i]]++;
        }
    }
    
    int answer = 1e9;
    for (auto &next : count) {
        answer = min(answer, next.second);
    }
    
    if (count.size() != 5) return 0;
    return answer;
}

int main() {
    init();
    cout << simulate();
    return 0;
}
