// 문제 링크: https://www.acmicpc.net/problem/1182
#include <iostream>
#include <vector>
using namespace std;

int n, s;
vector<int> nums;
vector<bool> visited;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        nums.push_back(temp);
        visited.push_back(false);
    }
}

void dfs(int nx, int x, int &sum, int &result) {
    if (sum == s && nx != 0) {
        result++;
    }
    
    for (int i = 0; i < n; i++) {
        if (visited[i] || x > i) {
            continue;
        }
        
        visited[i] = true;
        sum += nums[i];
        dfs(nx + 1, i, sum, result);
        visited[i] = false;
        sum -= nums[i];
    }
}

int simulate() {
    int sum = 0;
    int result = 0;
    dfs(0, 0, sum, result);
    return result;
}

int main() {
    init();
    cout << simulate();
    return 0;
}
