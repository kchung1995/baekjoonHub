// 문제 링크: https://www.acmicpc.net/problem/11501
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
}

long long simulate() {
    int n;
    vector<int> stocks;
    
    // 테스트 케이스마다 주어진 입력을 받는다.
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        stocks.push_back(temp);
    }
    
    long long answer = 0;
    int tempMax = stocks.back();
    
    // 뒤에서부터 보면서, 현재까지의 최대값과 비교; 작으면 더하고, 크면 최대값 갱신
    for (int i = stocks.size() - 2; i >= 0; i--) {
        if (stocks[i] < tempMax) {
            answer += (tempMax - stocks[i]);
        }
        else {
            tempMax = stocks[i];
        }
    }
    
    return answer;
}

int main() {
    init();
    while(t--) {
        cout << simulate() << '\n';
    }
    return 0;
}
