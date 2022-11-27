// 문제 링크: https://www.acmicpc.net/problem/2480
#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c;
}

int simulate() {
    // 모두 같은 경우
    if (a == b && b == c) {
        return 10000 + max(a, max(b, c)) * 1000;
    }
    if (a == b || b == c || a == c) {
        int sameFace = 0;
        if (a == b || a == c) {
            sameFace = a;
        }
        if (b == c) {
            sameFace = b;
        }
        return 1000 + sameFace * 100;
    }
    
    return max(a, max(b , c)) * 100;
}

int main() {
    init();
    cout << simulate();
    return 0;
}
