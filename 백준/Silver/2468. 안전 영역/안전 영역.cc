// 문제 링크: https://www.acmicpc.net/problem/2468
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 100

int n;
int maxRain = -1;
int grid[MAX_N][MAX_N] = {0, };

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void init() {
    // 주어지는 입력을 받는다.
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            maxRain = max(maxRain, grid[i][j]);
        }
    }
    maxRain++;
}

// 경계 밖으로 나가는지 확인
bool inBoundary (int x, int y) {
    if (0 <= x && x < n && 0 <= y && y < n) {
        return true;
    }
    return false;
}

int bfs(int height) {
    int count = 0;
    bool sinked[MAX_N][MAX_N] = {0, };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 비에 잠기는 영역을 찾기 위한 bfs 시작
            if (grid[i][j] <= height && !sinked[i][j]) {
                queue<pair<int, int> > q;
                sinked[i][j] = true;
                q.push({i, j});
                
                while(!q.empty()) {
                    int cx = q.front().first;
                    int cy = q.front().second;
                    q.pop();
                    
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cx + dx[dir];
                        int ny = cy + dy[dir];
                        if (!inBoundary(nx, ny)) {
                            continue;
                        }
                        if (sinked[nx][ny] || grid[nx][ny] > height) {
                            continue;
                        }
                        sinked[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    
    bool visited[MAX_N][MAX_N] = {0, };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 안전한 영역을 찾기 위한 bfs 시작
            if (!sinked[i][j] && !visited[i][j]) {
                queue<pair<int, int> > q;
                visited[i][j] = true;
                q.push({i, j});
                count++;
                
                while(!q.empty()) {
                    int cx = q.front().first;
                    int cy = q.front().second;
                    q.pop();
                    
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cx + dx[dir];
                        int ny = cy + dy[dir];
                        if (!inBoundary(nx, ny)) {
                            continue;
                        }
                        if (visited[nx][ny] || sinked[nx][ny]) {
                            continue;
                        }
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    
    return count;
}

int simulate() {
    int answer = -1;
    for (int i = 0; i <= maxRain; i++) {
        int temp = bfs(i);
        answer = max(answer, temp);
    }
    return answer;
}

int main() {
    init();
    cout << simulate();
    return 0;
}
