// 문제 링크: https://www.acmicpc.net/problem/2533
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX_N 1000001

int n;
vector<int> graph[MAX_N];
vector<int> tree[MAX_N];
int dp[MAX_N][2];
bool visited[MAX_N] = {false, };

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(dp, -1, sizeof(dp));
}

void treeInit(int current) {
    visited[current] = true;
    
    // 현재 노드에 연결된 노드를 확인
    for (int i = 0; i < graph[current].size(); i++) {
        int temp = graph[current][i];
        if (!visited[temp]) {
            tree[current].push_back(temp);
            treeInit(temp);
        }
    }
}

int dfs(int current, int state) {
    if (dp[current][state] != -1) {
        return dp[current][state];
    }
    
    if (state == 1) {
        dp[current][state] = 1;
        for (int i = 0; i < tree[current].size(); i++) {
            int temp = tree[current][i];
            dp[current][state] += min(dfs(temp, 0), dfs(temp, 1));
        }
    }
    else {
        dp[current][state] = 0;
        for (int i = 0; i < tree[current].size(); i++) {
            int temp = tree[current][i];
            dp[current][state] += dfs(temp, 1);
        }
    }
    
    return dp[current][state];
}

int solution() {
    treeInit(1);
    return min(dfs(1, 0), dfs(1, 1));
}

int main() {
    init();
    cout << solution();
    return 0;
}
