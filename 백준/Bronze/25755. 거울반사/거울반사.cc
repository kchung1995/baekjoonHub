// 문제 링크: https://www.acmicpc.net/problem/25755
#include <iostream>
using namespace std;
#define MAX_N 20

char w;
int n;
char board[MAX_N][MAX_N];

const char leftRight[10] = {'0', '1', '5', '?', '?', '2', '?', '?', '8', '?'};
const char upDown[10] = {'0', '1', '5', '?', '?', '2', '?', '?', '8', '?'};

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 주어지는 입력을 받는다.
    cin >> w >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
}

void simulate() {
    // 상하로 넘겼을 때의 결과 역시 같다.
    if (w == 'U' || w == 'D') {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                cout << upDown[board[i][j] - '0'] <<  ' ';
            }
            cout << '\n';
        }
    }
    // 마찬가지로, 좌우로 넘겼을 때의 결과는 같다.
    else if (w == 'L' || w == 'R') {
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                cout << leftRight[board[i][j] - '0'] <<  ' ';
            }
            cout << '\n';
        }
    }
}

int main() {
    init();
    simulate();
    return 0;
}
