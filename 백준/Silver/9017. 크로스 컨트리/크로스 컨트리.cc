// 문제 링크: https://www.acmicpc.net/problem/9017
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int t;

bool cmp (vector<int> a, vector<int> b) {
    if (a[1] == b[1]) return a[2] < b[2];
    return a[1] < b[1];
}

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
}

int simulate() {
    int n; cin >> n;
    vector<int> goalLines;
    vector<vector<int> > teams(201);    // 각 팀에 대한 정보
    
    // 먼저 팀원이 6명 이하인 팀을 거른다.
    for (int i = 1; i <= n; i++) {
        int currentTeam; cin >> currentTeam;
        goalLines.push_back(currentTeam);
        teams[currentTeam].push_back(i);
    }
    unordered_set<int> teamsLessThanSix;

    for (int i = 1; i < teams.size(); i++) {
        if (teams[i].size() < 6) {
            teamsLessThanSix.insert(i);
        }
    }
    
    
    vector<vector<int> > teamsAfter(201);   // 점수는 자격을 갖춘 팀에게만 주어진다.
    int score = 1;
    for (auto &next : goalLines) {
        if (teamsLessThanSix.find(next) != teamsLessThanSix.end()) continue;
        teamsAfter[next].push_back(score);
        score++;
    }
    
    vector<vector<int> > result;
    for (int i = 1; i < teamsAfter.size(); i++) {
        
        if (teamsAfter[i].size() < 6) continue;

        vector<int> tempResult;
        int sumScore = 0;
        for (int j = 0; j < 4; j++) {   // 상위 4명의 스코어 합산
            sumScore += teamsAfter[i][j];
        }
        // 팀 번호, 총합 점수, 5번째로 들어온 사람의 순위 기록
        tempResult.push_back(i);
        tempResult.push_back(sumScore);
        tempResult.push_back(teamsAfter[i][4]);
        result.push_back(tempResult);
    }
    
    sort(result.begin(), result.end(), cmp);
    
    return result[0][0];
}

int main() {
    init();
    while(t--) {
        cout << simulate() << '\n';
    }
    return 0;
}
