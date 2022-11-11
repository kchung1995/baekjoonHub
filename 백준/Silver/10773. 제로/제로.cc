// 문제 링크: https://www.acmicpc.net/problem/10773
#include <iostream>
#include <stack>
using namespace std;

int n;
stack<long long> s;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
}

long long simulate() {
    for (int i = 0; i < n; i++) {
        long long temp; cin >> temp;
        if (temp == 0) {
            s.pop();
            continue;
        }
        s.push(temp);
    }
    
    long long answer = 0;
    while(!s.empty()) {
        answer +=  s.top();
        s.pop();
    }
    return answer;
}

int main() {
    init();
    cout << simulate();
    return 0;
}
