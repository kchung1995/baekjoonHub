// 문제 링크: https://www.acmicpc.net/problem/1515
#include <iostream>
#include <string>
using namespace std;

string input;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> input;
}

int simulate() {
    int attempt = 1;
    int pointer = 0;
    
    // 숫자는 최대 3000자리이므로, 각 숫자와 비교하니 총 3만 회 시도한다.
    for (; attempt <= 30000; attempt++) {
        string temp = to_string(attempt);
        while(temp.size() > 0 && input.size() > 0) {
            if (temp[0] == input[0]) {
                input = input.substr(1);
            }
            temp = temp.substr(1);
        }
        if (input == "") {
            return attempt;
        }
    }
    return attempt;
}

int main() {
    init();
    cout << simulate();
    return 0;
}
