#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s[20000];
pair<string, int> p[20000];
pair<int, int> r, t;
int n, maxi = -1, pre = -1, l;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)cin >> s[i], p[i] = { s[i],i };
    sort(p, p + n);
    unique(p, p + n);
    for (int i = 1; i < n; i++) {
        for (l = 0; l<p[i - 1].first.size() && l<p[i].first.size() && p[i - 1].first[l] == p[i].first[l]; l++);
        if (l^pre) pre = l, t = { p[i - 1].second,p[i].second };
        else if (t.second > p[i].second) t.second = p[i].second;
        if (t.first > t.second) swap(t.first, t.second);
        if (maxi < l || maxi == l&&r>t) maxi = l, r = t;
    }
    cout << s[r.first] + '\n' + s[r.second];
    return 0;
}