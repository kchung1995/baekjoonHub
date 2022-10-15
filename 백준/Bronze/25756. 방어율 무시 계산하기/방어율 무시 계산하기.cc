// 문제 링크: https://www.acmicpc.net/problem/25756
#include <iostream>
using namespace std;

double v = 0.0;
int n;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
}

double simulate() {
    double potion;
    cin >> potion;
    
    potion /= 100;
    
    v = 1 - ((1 - v) * (1 - potion));
    return v * 100;
}

int main() {
    init();
    while(n--) {
        cout.precision(7);
        cout << simulate() << '\n';
    }
    return 0;
}
