// 문제 링크: https://www.acmicpc.net/problem/2512
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> budgets;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        budgets.push_back(temp);
    }
    sort(budgets.begin(), budgets.end());
    cin >> m;
}

int simulate() {
    int left = 0, right = budgets.back();
    int mid = 0;
    
    int lessMax = -1;
    
    while(left <= right) {
        mid = (left + right) / 2;
        int i;
        int sum = 0;
        
        // 앞에서부터 mid보다 작은 금액을 세어, 그대로 더한다.
        for (i = 0; i < n; i++) {
            if (budgets[i] < mid) {
                sum += budgets[i];
            }
            else {
                break;
            }
        }
        // mid보다 크거나 같은 금액의 수만큼 mid를 더한다.
        sum += (mid * (n - i));
        
        if (sum < m) {
            lessMax = max(lessMax, mid);
            left = mid + 1;
        }
        else if (sum > m) {
            right = mid - 1;
        }
        else {
            lessMax = max(lessMax, mid);
            break;
        }
    }
    
    return lessMax;
}

int main() {
    init();
    cout << simulate();
    return 0;
}
