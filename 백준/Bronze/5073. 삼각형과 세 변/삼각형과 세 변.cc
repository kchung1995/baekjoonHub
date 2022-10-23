// 문제 링크: https://www.acmicpc.net/problem/5073
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

string getTriangle(int a, int b, int c) {
    vector<int> sideList;
    sideList.push_back(a);
    sideList.push_back(b);
    sideList.push_back(c);
    
    sort(sideList.begin(), sideList.end());
    
    if (sideList[0] + sideList[1] <= sideList[2]) return "Invalid";
    if (sideList[0] == sideList[2]) return "Equilateral";
    if (sideList[0] == sideList[1] || sideList[1] == sideList[2]) return "Isosceles";
    return "Scalene";
}

int main() {
    init();
    while(1) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;
        cout << getTriangle(a, b, c) << '\n';
    }
    return 0;
}
