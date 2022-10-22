// 문제 링크: https://www.acmicpc.net/problem/7568
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int> > people; // 몸무게, 키
using namespace std;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int weight, height;
        cin >> weight >> height;
        people.push_back({weight, height});
    }
}

void simulate() {
    for (auto &compareFrom : people) {
        int rank = 1;
        for (auto &compareTo : people) {
            if (compareFrom.first < compareTo.first && compareFrom.second < compareTo.second) {
                rank++;
            }
        }
        cout << rank << ' ';
    }
    return;
}

int main() {
    init();
    simulate();
    return 0;
}
