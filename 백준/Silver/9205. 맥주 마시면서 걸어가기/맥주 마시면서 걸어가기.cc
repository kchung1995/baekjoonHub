// 문제 링크: https://www.acmicpc.net/problem/9205
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N 101

int t;
const int inDistance = 1000;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
}

int getDistance(int fx, int fy, int sx, int sy) {
    return (abs(fx - sx) + abs(fy - sy));
}

string simulate() {
    int n;
    vector<pair<int, int> > home;
    vector<pair<int, int> > convini;
    vector<pair<int, int> > goal;
    bool visited[MAX_N] = {0, };
    
    // 입력 받기
    cin >> n;
    int tempX, tempY;
    cin >> tempX >> tempY;
    home.push_back({tempX, tempY});
    for (int i = 0; i < n; i++) {
        cin >> tempX >> tempY;
        convini.push_back({tempX, tempY});
    }
    cin >> tempX >> tempY;
    goal.push_back({tempX, tempY});
    
    // bfs 시작
    queue<pair<int, int> > q;
    q.push({home[0].first, home[0].second});
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        // 현재 위치에서 목적지까지의 거리가 1000 이내인지 확인
        if (getDistance(cx, cy, goal[0].first, goal[0].second) <= inDistance) {
            return "happy";
        }
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            int tempDistance = getDistance(cx, cy, convini[i].first, convini[i].second);
            if (tempDistance <= inDistance) {
                visited[i] = true;
                q.push({convini[i].first, convini[i].second});
            }
        }
    }
    
    return "sad";
}

int main() {
    init();
    while(t--) {
        cout << simulate() << '\n';
    }
    return 0;
}
