// 문제 링크: https://www.acmicpc.net/problem/7682
#include <iostream>
#include <string>
using namespace std;

char board[3][3];

int getCount(char c) {
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {        //가로 3개 확인
            if (board[i][0] == c)     cnt++;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {        //세로 3개 확인
            if (board[0][i] == c)     cnt++;
        }
    }
    //대각선 2개 확인
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[1][1] == c)        cnt++;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[1][1] == c)     cnt++;
    }
    return cnt;
}

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

string simulate(string input) {
    int remain = 0, xCount = 0, oCount = 0;
    int cnt = 0;
    // 주어지는 입력을 받는다.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = input[cnt++];
            if (board[i][j] == '.') remain++;
            else if (board[i][j] == 'X') xCount++;
            else if (board[i][j] == 'O') oCount++;
        }
    }
    
    // 판이 꽉 찼다면, 'O' 3개가 연속되면 invalid
    if (remain == 0) {
        if (xCount - 1 != oCount) {
            return "invalid";
        }
        int result = getCount('O');
        if (result > 0) {
            return "invalid";
        }
    }
    // 남은 수가 짝수라면, 'X'가 'O'보다 1개 많고, 'X'가 승리
    else if (remain % 2 == 0 && remain!=0) {
        if (xCount - 1 != oCount) {
            return "invalid";
        }
        int result = getCount('O');
        if (result > 0) {
            return "invalid";
        }
        result = getCount('X');
        if (result == 0) {
            return "invalid";
        }
    }
    // 'X'와 'O'의 개수가 같고, 'O'가 승리
    else {
        if (xCount != oCount) {
            return "invalid";
        }
        int result = getCount('X');
        if (result > 0) {
            return "invalid";
        }
        result = getCount('O');
        if (result == 0) {
            return "invalid";
        }
    }
    
    return "valid";
}

int main() {
    init();
    while(1) {
        string command; cin >> command;
        if (command == "end") {
            break;
        }
        cout << simulate(command) << '\n';
    }
    return 0;
}
