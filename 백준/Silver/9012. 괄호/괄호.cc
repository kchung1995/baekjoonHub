// 문제 링크: https://www.acmicpc.net/problem/9012
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
}

void simulate() {
    stack<char> s;
    string input; cin >> input;
    // 입력받은 괄호 문자열을 탐색합니다.
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(') {
            s.push(input[i]);
        }
        if (input[i] == ')') {
            if (s.empty()) {
                cout << "NO\n";
                return;
            }
            s.pop();
        }
    }
    if (!s.empty()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    return;
}

int main() {
    init();
    while(n--) {
        simulate();
    }
    return 0;
}
