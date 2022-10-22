// 문제 링크: https://www.acmicpc.net/problem/1244
#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 101

int n;
bool switches[MAX_N];
int people;
vector<pair<int, int> > signs;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1 ; i <= n; i++) {
        cin >> switches[i];
    }
    cin >> people;
    for (int i = 0; i < people; i++) {
        int gender, number;
        cin >> gender >> number;
        signs.push_back({gender, number});
    }
}

void boySwitch(int switchNo) {
    for (int i = switchNo; i <= n; i += switchNo) {
        switches[i] = !switches[i];
    }
}

void girlSwitch(int switchNo) {
    int front = switchNo - 1;
    int end = switchNo + 1;
    
    if (switches[front] != switches[end]) {
        switches[switchNo] = !switches[switchNo];
        return;
    }
    
    while(1) {
        if (front < 1 || end > n) {
            front++;
            end--;
            break;
        }
        if (switches[front] != switches[end]) {
            front++;
            end--;
            break;
        }
        else {
            front--;
            end++;
        }
    }
    
    for (int i = front; i <= end; i++) {
        switches[i] = !switches[i];
    }
}

void printSwitches() {
    for (int i = 1; i <= n; i++) {
        if (switches[i]) cout << 1;
        else cout << 0;
        cout << ' ';
        if (i % 20 == 0) cout << '\n';
    }
}

void simulate() {
    for (int i = 0; i < people; i++) {
        if (signs[i].first == 1) {
            boySwitch(signs[i].second);
        }
        else {
            girlSwitch(signs[i].second);
        }
    }
}

int main() {
    init();
    simulate();
    printSwitches();
    return 0;
}
