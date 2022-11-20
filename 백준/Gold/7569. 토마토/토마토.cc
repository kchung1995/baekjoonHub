// 문제 링크: https://www.acmicpc.net/problem/7569
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 101

int m, n, h;
int grid[MAX_N][MAX_N][MAX_N];
queue<pair<int, pair<int, int> > > q;   // [x, [y, h]]
bool allTomatoesRedFromInit = true;

// 인접함: 위, 아래, 좌, 우, 앞, 뒤
int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 주어진 입력을 받는다.
    cin >> m >> n >> h;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j][k];
                if (grid[i][j][k] == 0) {
                    allTomatoesRedFromInit = false;
                }
                if (grid[i][j][k] == 1) {
                    q.push({i, {j, k}});
                }
            }
        }
    }
}

bool inBoundary (int x, int y, int hi) {
    if (0 > x || x >= n) return false;
    if (0 > y || y >= m) return false;
    if (0 > hi || hi >= h) return false;
    return true;
}

int simulate() {
    if (allTomatoesRedFromInit) {
        return 0;
    }

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second.first;
        int ch = q.front().second.second;
        q.pop();
        
        for (int dir = 0; dir < 6; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            int nh = ch + dh[dir];
            
            // 경계 밖으로 나가는 경우를 체크한다.
            if (!inBoundary(nx, ny, nh )) {
                continue;
            }
            // 토마토가 없는 공간을 체크한다.
            if (grid[nx][ny][nh] == -1) {
                continue;
            }
            // 아직 안 익은 토마토의 경우 (방문한 적 없음)
            if (grid[nx][ny][nh] == 0) {
                grid[nx][ny][nh] = grid[cx][cy][ch] + 1;
                q.push({nx, {ny, nh}});
            }
            // 날짜가 지나며 익은 토마토의 경우 (방문한 적 있음)
            else {
                if (grid[nx][ny][nh] > grid[cx][cy][ch] + 1) {
                    grid[nx][ny][nh] = grid[cx][cy][ch] + 1;
                    q.push({nx, {ny, nh}});
                }
            }
        }
    }
    
    int elapsedDate = 0;
    bool nonRedTomatoExists = false;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                elapsedDate = max(elapsedDate, grid[i][j][k]);
                if (!nonRedTomatoExists && grid[i][j][k] == 0) {
                    nonRedTomatoExists = true;
                }
            }
        }
    }
    
    if (nonRedTomatoExists) {
        return -1;
    }
    return elapsedDate - 1;
}

int main() {
    init();
    cout << simulate();
    return 0;
}
