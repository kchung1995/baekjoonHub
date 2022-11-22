// 문제 링크: https://www.acmicpc.net/problem/2473
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<long long> nums;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        nums.push_back(temp);
    }
}

void solution() {
    sort(nums.begin(), nums.end());
    
    vector<long long> result;
    long long closest = 3000000001;
    // 숫자 하나를 고정시키고, 나머지를 기준으로 binary search 진행
    for (int i = 0; i < nums.size() - 2; i++) {
        int start = i + 1;
        int end = nums.size() - 1;
        
        while (start < end) {
            long long temp = nums[i] + nums[start] + nums[end];
            if (abs(temp) < closest) {
                closest = abs(temp);
                result.clear();
                result.push_back(nums[i]);
                result.push_back(nums[start]);
                result.push_back(nums[end]);
            }
            if (temp == 0) break;
            if (temp < 0) {
                start++;
            }
            if (temp > 0) {
                end--;
            }
        }
    }

    sort(result.begin(), result.end());
    cout << result[0] << ' ' << result[1] << ' ' << result[2];
    return;
}

int main() {
    init();
    solution();
    return 0;
}
