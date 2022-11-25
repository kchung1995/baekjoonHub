// 문제 링크: https://www.acmicpc.net/problem/2632
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int customerPizza;
int m, n;
vector<int> pizzaA;
vector<int> pizzaB;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> customerPizza;
    cin >> m >> n;
    // 피자 A의 미리 잘라진 피자조각의 크기
    for (int i = 0; i < m; i++) {
        int temp; cin >> temp;
        pizzaA.push_back(temp);
    }
    // 피자 B의 미리 잘라진 피자조각의 크기
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        pizzaB.push_back(temp);
    }
}

int solution() {
    vector<int> a;
    vector<int> b;
    a.push_back(0);
    b.push_back(0);
    
    int temp = 0;
    // pizza A
    for (int i = 0; i < m; i++) {
        if (customerPizza >= pizzaA[i]) {
            a.push_back(pizzaA[i]);
            int j = i + 1;
            if (j == m) { // 원형에 대한 처리
                j = 0;
            }
            int tempSum = pizzaA[i];
            
            while (tempSum <= customerPizza && i != j) {
                tempSum += pizzaA[j];
                if (tempSum <= customerPizza) {
                    a.push_back(tempSum);
                }
                else {
                    break;
                }
                j++;
                if (j == m) { // 원형에 대한 처리
                    j = 0;
                }
                if (i == j && temp == 1) {
                    a.pop_back();
                }
                if (i == j && temp == 0) {
                    temp = 1;
                }
            }
        }
    }
    // pizza B
    temp = 0;
    for (int i = 0; i < n; i++) {
        if (customerPizza >= pizzaB[i]) {
            b.push_back(pizzaB[i]);
            int j = i + 1;
            if (j == n) {   // 원형에 대한 처리
                j = 0;
            }
            int tempSum = pizzaB[i];
            
            while (tempSum <= customerPizza && i != j) {
                tempSum += pizzaB[j];
                if (tempSum <= customerPizza) {
                    b.push_back(tempSum);
                }
                else {
                    break;
                }
                j++;
                if (j == n) {   // 원형에 대한 처리
                    j = 0;
                }
                if (i == j && temp == 1) {
                    b.pop_back();
                }
                if (i == j && temp == 0) {
                    temp = 1;
                }
            }
        }
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int result = 0;
    for (int i = 0; i < a.size(); i++) {
        result +=
        upper_bound(b.begin(),b.end(), customerPizza - a[i])-
        lower_bound(b.begin(),b.end(), customerPizza - a[i]);
    }
    
    return result;
}

int main() {
    init();
    cout << solution();
    return 0;
}
