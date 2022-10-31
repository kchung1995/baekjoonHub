// 문제 링크: https://www.acmicpc.net/problem/10431
#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 20

int p;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> p;
}

void simulate() {
    int t;
    vector<int> lineup;
    // 각 테스트 케이스마다 주어지는 입력을 받는다.
    cin >> t;
    for (int i = 0; i < MAX_N; i++) {
        int temp; cin >> temp;
        lineup.push_back(temp);
    }
    int answer = 0;
    
    for (int i = 0; i < MAX_N; i++) {
        int currentMax = 1e9;
        int maxIndex = i;
        for (int j = 0; j < i; j++) {
            if (lineup[j] > lineup[i] && lineup[j] < currentMax) {
                currentMax = lineup[j];
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            vector<int> temp;
            for (int j = 0; j < maxIndex; j++) {
                temp.push_back(lineup[j]);
            }
            temp.push_back(lineup[i]);
            for (int j = maxIndex; j < i; j++) {
                temp.push_back(lineup[j]);
            }
            for (int j = i + 1; j < MAX_N; j++) {
                temp.push_back(lineup[j]);
            }
            lineup = temp;
            answer += i - maxIndex;
        }
    }
    cout << t << ' ' << answer << '\n';
}

int main() {
    init();
    while(p--) {
        simulate();
    }
    return 0;
}
