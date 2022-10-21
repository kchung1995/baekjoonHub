// 문제 링크: https://www.acmicpc.net/problem/1205
#include <iostream>
using namespace std;
#define MAX_N 51

int n;
int newScore;
int p;
int list[MAX_N];

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 주어지는 입력을 받는다.
    cin >> n >> newScore >> p;
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
}

int simulate() {
    
    if (n == 0) return 1;
    
    int answer = 0;
    int newRank = 1;
    
    for (int i = 0; i < n; i++) {
        if (newScore < list[i]) newRank++;
        else if (newScore != list[i]) break;
        answer++;
    }
    
    if (answer == p) return -1;
    return newRank;

}

int main() {
    init();
    cout << simulate();
    return 0;
}
