// 문제 링크: https://www.acmicpc.net/problem/1138
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> lineup;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        lineup.push_back(temp);
    }
}

void simulate() {
    vector<int> answer(n, -1);
    
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (answer[j] == -1) {
                count++;
            }
            if (count > lineup[i - 1]) {
                answer[j] = i;
                break;
            }
        }
    }
    
    for (auto &next : answer) {
        cout << next << ' ';
    }
}

int main() {
    init();
    simulate();
    return 0;
}
