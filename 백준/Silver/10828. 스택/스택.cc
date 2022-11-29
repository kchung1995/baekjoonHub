// 문제 링크: https://www.acmicpc.net/problem/10828
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n;
stack<int> s;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
}

void simulate() {

    while(n--) {
        string command;
        
        cin >> command;
        if (command == "push") {
            int value;
            cin >> value;
            s.push(value);
            continue;
        }
        if (command == "pop") {
            if (s.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << s.top() << '\n';
                s.pop();
            }
        }
        if (command == "size") {
            cout << s.size() << '\n';
        }
        if (command == "empty") {
            if (s.empty()) {
                cout << 1;
            }
            else {
                cout << 0;
            }
            cout << '\n';
        }
        if (command == "top") {
            if (s.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << s.top() << '\n';
            }
        }
    }
}

int main() {
    init();
    simulate();
    return 0;
}
