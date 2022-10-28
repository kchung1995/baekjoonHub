// 문제 링크: https://www.acmicpc.net/problem/23971
#include <iostream>
using namespace std;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

int maxPeople(int &h, int &w, int &n, int &m) {
    
    int heightAvailable = ((h - 1) / (n + 1)) + 1;
    int widthAvailable = ((w - 1) / (m + 1)) + 1;
    
    return heightAvailable * widthAvailable;
}

int main() {
    init();
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    cout << maxPeople(h, w, n, m);
    return 0;
}
