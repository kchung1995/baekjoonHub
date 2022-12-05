// 문제 링크: https://www.acmicpc.net/problem/10815
#include <iostream>
#include <unordered_set>
using namespace std;

int n;
unordered_set<int> holdingCards;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        holdingCards.insert(temp);
    }
}

void simulate(int m) {
    for (int i = 0; i < m; i++) {
        int temp; cin >> temp;
        if (holdingCards.find(temp) == holdingCards.end()) {
            cout << 0;
        }
        else {
            cout << 1;
        }
        cout << ' ';
    }
    cout << '\n';
}

int main() {
    init();
    int m; cin >> m;
    simulate(m);
    return 0;
}
