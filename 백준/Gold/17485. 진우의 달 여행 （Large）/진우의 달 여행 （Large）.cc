// 문제 링크: https://www.acmicpc.net/problem/17484
#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 1001
#define INF 0x3f3f3f3f


int n, m, ans = INF;
int matrix[MAX_N][MAX_N];
int d[MAX_N][MAX_N][4];
int dc[] = {0, 1, 0, -1};

int dfs(int x, int y, int dir){

    if (y < 1 || y > m) return INF; // 경계 밖으로 나가는 경우
    if (x == n) return matrix[x][y]; // 도착 지점에 도달한 경우
    
    int &answer = d[x][y][dir];
    if (answer != INF) return answer;

    for (int i = 1; i <= 3; i++){
        if (i == dir) continue;
        answer = min(answer, matrix[x][y] + dfs(x + 1, y + dc[i], i));
    }
    return answer;
}

int simulate() {
    int ans = INF;
    for (int i = 1; i <= m; i++) {
        ans = min(ans, dfs(0,i,0));
    }
    return ans;
}

void init() {
    // 문제에서 주어진 입력을 받는다.
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];
        }
    }
    memset(d, INF, sizeof(d));
}

int main(){
    init();
    cout << simulate();
    return 0;
}
