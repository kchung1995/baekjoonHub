// 문제 링크: https://www.acmicpc.net/problem/3758
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tc;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> tc;
}

int simulate() {
    int n, k, t, m;
    int d[101][101] = {0, };
    int tim[101] = {0, };
    int cnt[101] = {0, };
    
    cin >> n >> k >> t >> m;
    t--;
    for (int a = 0; a < m; a++) {
        int i, j, s;
        cin >> i >> j >> s;
        i--; j--;
        
        d[i][j] = max(d[i][j], s);
        cnt[i]++;
        tim[i] = a;
    }
    
    vector<pair<int, pair<int, pair<int, int> > > > grades;
    for (int a = 0; a < n; a++) {
        int scoreSum = 0;
        for (int b = 0; b < k; b++) {
            scoreSum += d[a][b];
        }
        grades.push_back({scoreSum, {-cnt[a], {-tim[a], a}}});
    }
    sort(grades.begin(), grades.end());
    
    int answer = 0;
    for (int a = 0; a < n; a++) {
        if (grades[a].second.second.second == t) {
            return n - a;
        }
    }
    return answer;
}
 
int main() {
    init();
    while(tc--) {
        cout << simulate() << '\n';
    }
    return 0;
}
