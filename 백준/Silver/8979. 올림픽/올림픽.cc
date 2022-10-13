// 문제 출처: https://www.acmicpc.net/problem/8979
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<vector<int> > teams;

bool cmp(vector<int> a, vector<int> b) {
    if (a[1] == b[1]) { // 금메달의 수가 같다면
        if (a[2] == b[2])  {// 은메달의 수가 같다면
            return a[3] > b[3];
        }
        return a[2] > b[2];
    }
    return a[1] > b[1];
}

void init() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int country, gold, silver, bronze;
        cin >> country >> gold >> silver >> bronze;
        vector<int> team = {country, gold, silver, bronze};
        teams.push_back(team);
    }
}

int simulate() {
    sort(teams.begin(), teams.end(), cmp);
    
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        int tempAns = -1;
        if (teams[i][0] == k) {
            tempAns = i + 1;
            
            for (int j = i; j >= 0; j--) {
                if (teams[j][1] == teams[i][1] && teams[j][2] == teams[i][2] && teams[j][3] == teams[i][3]) {
                    tempAns--;
                }
                else break;
            }
            answer = tempAns;
            break;
        }
    }
    
    return answer + 1;
}

int main() {
    init();
    cout << simulate();
    return 0;
}
