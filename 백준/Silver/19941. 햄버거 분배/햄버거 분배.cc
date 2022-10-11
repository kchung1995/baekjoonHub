// 문제 출처: https://www.acmicpc.net/problem/19941
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, k;
string input;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    cin >> input;
}

bool inBoundary(int i) {
    if (0 <= i && i < input.size()) return true;
    return false;
}

int leftSimulate(string table) {
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if (table[i] != 'P') continue;
        for (int j = i - k; j <= i + k; j++) {
            if (!inBoundary(j)) continue;
            if (table[j] == 'H') {
                answer++;
                table[j] = 'X';
                break;
            }
        }
    }
    return answer;
}

int rightSimulate(string table) {
    int answer = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (table[i] != 'P') continue;
        for (int j = i + k; j >= i + k; j--) {
            if (!inBoundary(j)) continue;
            if (table[j] == 'H') {
                answer++;
                table[j] = 'X';
                break;
            }
        }
    }
    return answer;
}

int main() {
    init();
    cout << max(leftSimulate(input), rightSimulate(input));
    return 0;
}
