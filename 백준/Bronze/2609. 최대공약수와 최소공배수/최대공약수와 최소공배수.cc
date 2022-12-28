// 문제 링크: https://www.acmicpc.net/problem/2609
#include <iostream>
using namespace std;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void simulate() {
    int a, b;
    cin >> a >> b;
    int gcdVal = gcd(a, b);
    cout << gcdVal << '\n' << (a*b/gcdVal);
}

int main() {
    init();
    simulate();
    return 0;
}
