// 문제 출처: https://www.acmicpc.net/problem/25822
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
double coin;
vector<int> solved;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> coin;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        solved.push_back(temp);
    }
}

/**
 최대값 구하기
 */
int getMaxVal(int left, int right) {
    int answer = -1;
    for (int i = left; i <= right; i++) {
        answer = max(answer, solved[i]);
    }
    return answer;
}

void solution() {
    // 먼저 사용할 수 있는 스트릭 프리즈의 갯수를 구한다. 프리즈는 최대 2개까지 사용 가능.
    int freeze = 0;
    if (coin < 0.99) freeze = 0;
    else if (coin < 1.98) freeze = 1;
    else freeze = 2;
    
    int maxStreak = -1;

    int left = 0, right = 0;
    int currentStreakFreeze = freeze;
    
    while(1) {
        // 만약 해당 날에 문제를 풀지 않았다면
        if (solved[right] == 0) {
            // 만약 스트릭 프리즈가 남았다면
            if (currentStreakFreeze > 0) {
                currentStreakFreeze--;
                maxStreak = max(maxStreak, right - left + 1);
                right++;
            }
            // 만약 스트릭 프리즈가 없다면
            else {
                // 만약 프리즈도 없고 더 회수할 수도 없다면
                if (left == right) {
                    left++; right++;
                }
                else {
                    if (solved[left] == 0) {
                        currentStreakFreeze++;  // 얘는 freeze의 값을 초과할 수 없음
                    }
                    left++;
                }
            }
        }
        // 해당 날에 문제를 풀었다면
        else {
            maxStreak = max(maxStreak, right - left + 1);
            right++;
        }
        
        // 종료 조건
        if (right == n) break;
    }
    
    cout << maxStreak << '\n' << getMaxVal(0, n - 1);
    return;
}

int main() {
    init();
    solution();
    return 0;
}
