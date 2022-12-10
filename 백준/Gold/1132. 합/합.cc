// 문제 링크: https://www.acmicpc.net/problem/1132
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define MAX_I 10

int n, z;
vector<string> inputs;
bool isFront[MAX_I] = {0, };
long long charScore[MAX_I] = {0, };

bool cmp (long long &a, long long &b) {
    return a > b;
}

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string temp; cin >> temp;
        inputs.push_back(temp);
        isFront[temp[0] - 'A'] = true;
    }
}

void getPriorityScore() {
    for (auto &next : inputs) {
        long long score = 1;
        for (int i = next.size() - 1; i >= 0; i--) {
            charScore[next[i] - 'A'] += score;
            score *= 10;
        }
    }
}

void charToInt() {
    z = 0;
    for (int i = 0; i < 10; i++) {
        if (!isFront[i]) {
            z = i;
            break;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (!isFront[i] && charScore[i] < charScore[z]) {
            z = i;
        }
    }
    charScore[z] = 0;
}

long long simulate() {
    getPriorityScore();
    charToInt();
    sort(charScore, charScore + 10, cmp);
    
    long long result = 0;
    for (int i = 0; i < 10; i++)
        result += (9 - i) * charScore[i];
    return result;
}

int main() {
    init();
    cout << simulate();
    return 0;
}
