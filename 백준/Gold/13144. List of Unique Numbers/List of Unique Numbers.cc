#include <iostream>
using namespace std;
#define MAX_N 100001

long long n;
int arr[MAX_N];
bool checked[MAX_N] = {0, };

void init() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

long long simulate() {
    long long ans = n * (n + 1) / 2;
    int lt = 0;
    int rt = 1;
    checked[arr[lt]] = true;
    while (rt < n) {
        if (checked[arr[rt]]){
            checked[arr[lt]] = false;
            lt++;
            ans -= n - rt;
        }else {
            checked[arr[rt]] = true;
            rt++;
        }
    }
    return ans;
}

int main() {
    init();
    cout << simulate();
    return 0;
}
