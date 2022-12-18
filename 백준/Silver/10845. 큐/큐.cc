// 문제 링크: https://www.acmicpc.net/problem/10845
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
}

int empty(queue<int> &q) {
    if (q.empty()) {
        return 1;
    }
    return 0;
}

void push(queue<int> &q) {
    int quantity; cin >> quantity;
    q.push(quantity);
}

int pop(queue<int> &q) {
    if (empty(q) == 1) {
        return -1;
    }
    int result = q.front();
    q.pop();
    return result;
}

int size(queue<int> &q) {
    return (int)q.size();
}

int front(queue<int> &q) {
    if (empty(q) == 1) {
        return -1;
    }
    return q.front();
}

int back(queue<int> &q) {
    if (empty(q) == 1) {
        return -1;
    }
    return q.back();
}

void simulate() {
    queue<int> q;
    
    string command;
    while(n--) {
        cin >> command;
        if (command == "push") {
            push(q);
        }
        else if (command == "pop") {
            cout << pop(q) << '\n';
        }
        else if (command == "size") {
            cout << size(q) << '\n';
        }
        else if (command == "empty") {
            cout << empty(q) << '\n';
        }
        else if (command == "front") {
            cout << front(q) << '\n';
        }
        else if (command == "back") {
            cout << back(q) << '\n';
        }
    }
}

int main() {
    init();
    simulate();
    return 0;
}
