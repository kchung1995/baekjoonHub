#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<pair<string, int> > candidates;

bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    cin >> n;
    while(n--) {
        string name;
        int votes;
        cin >> name >> votes;
        candidates.push_back({name, votes});
    }
    
    sort(candidates.begin(), candidates.end(), cmp);
    
    cout << candidates[0].first;
    return 0;
}