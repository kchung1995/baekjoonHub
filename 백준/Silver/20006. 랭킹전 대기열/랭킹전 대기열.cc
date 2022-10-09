// 문제 링크: https://www.acmicpc.net/problem/20006
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int p, m;
vector<vector<pair<int, string> > > rooms;

bool inRange(int range, int userLevel) {
    if (range - 10 <= userLevel && userLevel <= range + 10) return true;
    return false;
}

bool cmp(pair<int, string> a, pair<int, string> b) {
    return a.second < b.second;
}

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> p >> m;
}

void getUsers() {
    for (int i = 0; i < p; i++) {
        int level; string userId;
        cin >> level >> userId;
        
        // 만약 방이 하나도 존재하지 않는다면
        if (rooms.empty()) {
            // 방을 하나 만들고, 본인을 포함시킨다.
            vector<pair<int, string> > room;  // 레벨, 아이디
            room.push_back({level, userId});
            rooms.push_back(room);
            continue;
        }
        
        // 방이 존재한다면
        // 방에 들어갈 수 있으려면
        // 1. 방이 꽉 찼으면 안 되고
        // 2. 방장의 레벨로부터 +- 10 이내여야 한다.
        
        bool hasJoined = false;
        for (vector<pair<int, string> > &next : rooms) {
            // 방의 정원이 다 찼으면 넘어간다.
            if (next.size() == m) continue;
            // 레벨 범위에 맞는지 확인한다.
            // 방장의 레벨 next[0].first, 참가자의 레벨 level
            if (!inRange(next[0].first, level)) continue;
            
            // 방의 정원이 꽉 차지도 않았고, 레벨 범위에도 맞는 방을 찾았다.
            hasJoined = true;
            next.push_back({level, userId});
            break;
        }
        
        // 만약 만족하는 방을 못 찾았으면 방을 만들도록 하자.
        if (!hasJoined) {
            // 방을 하나 만들고, 본인을 포함시킨다.
            vector<pair<int, string> > room;  // 레벨, 아이디
            room.push_back({level, userId});
            rooms.push_back(room);
        }
    }
}

void printRoomStatus() {
    // 각 방을 돌면서
    for (vector<pair<int, string> > &next : rooms) {
        // 만약 방이 다 찼으면
        if (next.size() == m) {
            cout << "Started!\n";
        }
        else {
            cout << "Waiting!\n";
        }
        // 정렬하고
        sort(next.begin(), next.end(), cmp);
        for (pair<int, string> &user : next) {
            cout << user.first << ' ' << user.second << '\n';
        }
    }
}

int main() {
    init();
    getUsers();
    printRoomStatus();
    return 0;
}
