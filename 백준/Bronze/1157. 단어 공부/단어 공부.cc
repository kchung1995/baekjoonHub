#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string x;
    int alp[26];
    int max = 0;
    char ans;
    for (int i = 0; i < sizeof(alp) / sizeof(int); i++) {
        alp[i] = 0;
    }
    cin >> x;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] >= 'a') {
            alp[x[i] - 'a']++;
        }
        else alp[x[i] - 'A'] ++;
    }

    for (int i = 0; i < sizeof(alp) / sizeof(int); i++) {
        if (alp[i] == max) {
            ans = '?';
        }
        else if (alp[i] > max) {
            max = alp[i];
            ans = 'A' + i;
        }
    }
    cout << ans;
    return 0;
}