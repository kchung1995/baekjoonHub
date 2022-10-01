// 문제 링크: https://www.acmicpc.net/problem/5972
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 50001

int n, m;
vector<vector<pair<int, int> > > roads(MAX_N);

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;
        roads[from].push_back({to, dist});
        roads[to].push_back({from, dist});
    }
}

int bfs() {
    int dist[MAX_N];
    for (int i = 0; i <= n; i++) {
        dist[i] = 1e9;
    }
    dist[1] = 0;
    
    queue<int> q;
    q.push(1);
    
    while(!q.empty()) {
        int pos = q.front();
        q.pop();
        
        for (pair<int, int> &next : roads[pos]) {
            int tempDist = dist[pos] + next.second;
            if (tempDist >= dist[next.first]) continue;
            
            dist[next.first] = tempDist;
            q.push(next.first);
        }
    }
    
    return dist[n];
}

int main() {
    init();
    cout << bfs();
    return 0;
}
