// 문제 링크: https://www.acmicpc.net/problem/2531
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, d, k, c;
int temp;
vector<int> convoy;
unordered_map<int, int> sushi;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        convoy.push_back(temp);
    }
    // 계산의 편의성을 위해 입력을 그대로 한번 더 넣는다. 총 길이 2n (0 ~ 2n - 1)
//    for (int &next : convoy) {
//        convoy.push_back(next);
//    }
    for (int i = 0; i < n; i++) {
        convoy.push_back(convoy[i]);
    }
}

int simulate() {
    int maxSushi = 0;
    
    // 먼저 시작점에서부터 먹을 수 있는 초밥의 가지수를 센다.
    for (int i = 0; i < k; i++) {
        // 아직 먹은 적 없는 경우
        if (sushi.find(convoy[i]) == sushi.end()) {
            sushi.insert({convoy[i], 1});
        }
        else sushi[convoy[i]]++;
    }
    maxSushi = (int)sushi.size();
    if (sushi.find(c) == sushi.end()) {
        maxSushi++;
    }
    
    // 초밥을 먹을 수 있는 경우의 수를 탐색한다.
    for (int i = 0; i < n; i++) {
        // 맨 앞의 초밥은 빼고
        if (sushi[convoy[i]] <= 1) {
            sushi.erase(convoy[i]);
        }
        else sushi[convoy[i]]--;
        // 맨 뒤의 초밥은 더하고
        if (sushi.find(convoy[i + k]) == sushi.end()) {
            sushi.insert({convoy[i + k], 1});
        }
        else sushi[convoy[i + k]]++;
        int couponSushi = 0;
        if (sushi.find(c) == sushi.end()) couponSushi++;
        
        maxSushi = max(maxSushi, (int)sushi.size() + couponSushi);
    }
    
    return maxSushi;
}

int main() {
    init();
    cout << simulate();
    return 0;
}
