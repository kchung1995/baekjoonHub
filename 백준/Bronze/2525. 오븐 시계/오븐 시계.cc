// 문제 링크: https://www.acmicpc.net/problem/2525
#include <iostream>
using namespace std;

int hour, minute;
int runMinute = 0;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> hour >> minute;
    cin >> runMinute;
}

void solution() {
    minute +=  runMinute;
    hour += minute / 60;
    minute %= 60;
    hour %= 24;
    
    cout << hour << ' ' << minute;
    return;
}

int main() {
    init();
    solution();
    return 0;
}
