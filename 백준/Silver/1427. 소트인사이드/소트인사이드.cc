// 문제 링크: https://www.acmicpc.net/problem/1427
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string input;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> input;
}

string solution() {
    sort(input.begin(), input.end(), greater<int>());
    return input;
}

int main() {
    init();
    cout << solution();
    return 0;
}
