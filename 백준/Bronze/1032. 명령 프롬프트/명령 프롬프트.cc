// 문제 링크: https://www.acmicpc.net/problem/1032
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_L 50

int n;
vector<string> command;
string candidate;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string temp; cin >> temp;
        command.push_back(temp);
    }
    
    candidate = command[0];
}

string simulate() {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < command[0].size(); j++) {
            if (candidate[j] != command[i][j]) {
                candidate[j] = '?';
            }
        }
    }
    
    return candidate;
}

int main() {
    init();
    cout << simulate();
    return 0;
}
