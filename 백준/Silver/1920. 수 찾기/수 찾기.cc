// 문제 링크: https://www.acmicpc.net/problem/1920
#include <iostream>
#include <unordered_set>
using namespace std;

int n, m;
unordered_set<int> nums;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums.insert(temp);
    }
}

bool doesExist(int &temp) {
    if (nums.find(temp) == nums.end()) {
        return false;
    }
    return true;
}

void simulate() {
    int m; cin >> m;
    int temp;
    while(m--) {
        cin >> temp;
        if(doesExist(temp)) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }
}

int main() {
    init();
    simulate();
    return 0;
}
