// 문제 링크: https://www.acmicpc.net/problem/5014
#include <iostream>
#include <queue>
using namespace std;
#define MAX_F 1000001
#define INF 1e9

int dist[MAX_F];
queue<int> floors;
vector<int> buttons;

// 총 f층, 강호가 있는 곳 s, 목적지 g, 위로 u층, 아래로 d층
int f, s, g;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int u, d;
    cin >> f >> s >> g >> u >> d;
    buttons.push_back(u);
    buttons.push_back(-d);
    for (int i = 1; i <= f; i++) {
        dist[i] = INF;
    }
}

int simulate() {
    dist[s] = 0;
    floors.push(s);
    
    while(!floors.empty()) {
        int current = floors.front();
        floors.pop();
        
        for (int next = 0; next < 2; next++) {
            int nextFloor = current + buttons[next];
            
            if (nextFloor < 1 || nextFloor > f) {
                continue;
            }
            if (dist[nextFloor] > dist[current] + 1) {
                dist[nextFloor] = dist[current] + 1;
                floors.push(nextFloor);
            }
        }
    }
    
    return dist[g];
}

int main() {
    init();
    int result = simulate();
    if (result == INF) {
        cout << "use the stairs";
        return 0;
    }
    cout << result;
    return 0;
}
