// 문제 링크: https://www.acmicpc.net/problem/10867
#include <iostream>
#include <set>
using namespace std;

int n;

void init() {
    ios::sync_with_stdio(false);
    cin >> n;
}

void solution() {
    set<int> nums;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums.insert(temp);
    }
    
    for (auto &next : nums) {
        cout << next << ' ';
    }
}

int main() {
    init();
    solution();
    return 0;
}
