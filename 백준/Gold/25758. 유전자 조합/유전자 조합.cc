// 문제 출처: https://www.acmicpc.net/problem/25758
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int n;
vector<string> firstGen;
unordered_set<char> secondGen;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 문제에서 주어지는 입력을 받는다.
    cin >> n;
    unordered_map<string, int> buffer;
    for (int i = 0; i < n; i++) {
        string temp; cin >> temp;
        // 각 입력이 들어오는 횟수를 센다.
        if (buffer.find(temp) == buffer.end()) {
            buffer.insert({temp, 1});
        }
        else buffer[temp]++;
    }
    
    for (auto &next : buffer) {
        if (next.second > 1) {
            firstGen.push_back(next.first);
            firstGen.push_back(next.first);
        }
        else if (next.second == 1) {
            firstGen.push_back(next.first);
        }
    }
}

void simulate() {
    
    // 원소가 하나뿐인 경우
    if (firstGen.size() == 1) {
        cout << 0;
        return;
    }
    
    // 각 1세대 유전자를 다른 1세대 유전자와 조합한다.
    for (int i = 0; i < firstGen.size() - 1; i++) {
        for (int j = i + 1; j < firstGen.size(); j++) {
            
            // i의 앞과 j의 뒤를 비교한다.
            if (firstGen[i][0] > firstGen[j][1]) {
                secondGen.insert(firstGen[i][0]);   // 표현형으로 나타내기
            }
            else {
                secondGen.insert(firstGen[j][1]);   // 표현형으로 나타내기
            }
            
            // i의 뒤와 j의 앞을 비교한다.
            if (firstGen[i][1] > firstGen[j][0]) {
                secondGen.insert(firstGen[i][1]);   // 표현형으로 나타내기
            }
            else {
                secondGen.insert(firstGen[j][0]);   // 표현형으로 나타내기
            }
        }
    }
    
    vector<char> ans;
    // 생성된 2세대 유전자의 표현형을 출력한다.
    for (auto &next : secondGen) {
        ans.push_back(next);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (char &next : ans) {
        cout << next << ' ';
    }
}

int main() {
    init();
    simulate();
    return 0;
}
