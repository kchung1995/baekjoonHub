// 문제 링크: https://www.acmicpc.net/problem/25757
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int n; char y;
unordered_set<string> candidates;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 주어진 입력을 받는다.
    cin >> n >> y;
    for (int i = 0; i < n; i++) {
        string temp; cin >> temp;
        candidates.insert(temp);
    }
}

int simulate() {
    int div = 0;
    // 각 게임에 필요한 사람들의 수를 정의에 따라 구한다.
    switch(y) {
        case 'Y':
            div = 1; break;
        case 'F':
            div = 2; break;
        case 'O':
            div = 3; break;
        default:
            break;
    }
    
    return candidates.size() / div;
}

int main() {
    init();
    cout << simulate();
    return 0;
}