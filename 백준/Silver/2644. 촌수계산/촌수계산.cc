// 문제 링크: https://www.acmicpc.net/problem/2644
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
#define MAX_N 101
#define INF 2147483647

int n, m;
int from, to;
unordered_map<int, vector<int> > graph;
int dist[MAX_N];

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 주어지는 입력을 받는다.
    cin >> n;
    cin >> from >> to;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[from] = 0;
}

int simulate() {
    
    queue<int> q;
    q.push(from);
    
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        
        for (auto &next : graph[now]) {
            if (dist[next] > dist[now] + 1) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
    
    if (dist[to] == INF) return -1;
    return dist[to];
}

int main() {
    init();
    cout << simulate();
    return 0;
}
