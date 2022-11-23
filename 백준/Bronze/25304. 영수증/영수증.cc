// 문제 링크: https://www.acmicpc.net/problem/25304
#include <iostream>
using namespace std;

int n;
int total;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> total >> n;
}

void simulate() {
    while(n--) {
        int price, quantity;
        cin >> price >> quantity;
        total -= (price * quantity);
    }
    
    if (total == 0) {
        cout << "Yes";
        return;
    }
    cout << "No";
    return;
}

int main() {
    init();
    simulate();
    return 0;
}
