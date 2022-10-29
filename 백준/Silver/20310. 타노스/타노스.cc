// 문제 링크: https://www.acmicpc.net/problem/20310
#include <iostream>
#include <string>
using namespace std;

string input;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> input;
}

string thanosify() {
    int numberofZero = 0;
    int numberofOne = 0;
    
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '0') numberofZero++;
        if (input[i] == '1') numberofOne++;
    }
    
    numberofZero /= 2;
    numberofOne /= 2;
    
    int zeroCount = 0;
    int oneCount = 0;
    
    // 0을 앞에서부터 제거한다.
    for (int i = input.size() - 1; i >= 0; i--) {
        if (input[i] == '0') {
            input[i] = 'x';
            zeroCount++;
        }
        if (zeroCount >= numberofZero) break;
    }
    
    // 1을 뒤에서부터 제거한다.
    for (int i = 0; i < input.size(); i++){
        if (input[i] == '1') {
            input[i] = 'x';
            oneCount++;
        }
        if (oneCount >= numberofOne) break;
    }
    
    string answer = "";
    for (int i = 0; i < input.size(); i++) {
        if (input[i] != 'x') answer += input[i];
    }
    return answer;
}

int main() {
    init();
    cout << thanosify();
    return 0;
}
