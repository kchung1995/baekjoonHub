// 문제 링크: https://www.acmicpc.net/problem/11723
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int m;
unordered_set<int> nums;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m;
}

void add(int input) {
    // 집합에 input이 없으면
    if (nums.find(input) == nums.end()) {
        nums.insert(input);
    }
}

void remove(int input) {
    // 집합에 input이 있으면
    if (nums.find(input) != nums.end()) {
        nums.erase(input);
    }
}

int check(int input) {
    // 집합에 input이 있으면
    if (nums.find(input) != nums.end()) {
        return 1;
    }
    // 없으면
    else {
        return 0;
    }
}

void toggle(int input) {
    // 집합에 input이 없으면
    if (nums.find(input) == nums.end()) {
        nums.insert(input);
    }
    // 있으면
    else {
        nums.erase(input);
    }
}

void empty() {
    nums.clear();
}

void all() {
    for (int i = 1; i <= 20; i++) {
        if (nums.find(i) == nums.end()) {
            nums.insert(i);
        }
    }
}

void simulate() {
    for (int i = 0; i < m; i++) {
        string command;
        int element;
        cin >> command;
        
        // C++에서는 string을 switch문에 사용할 수 없다.
        if (command == "all") {
            all();
        }
        else if (command == "empty") {
            empty();
        }
        else {
            cin >> element;
            if (command == "add") {
                add(element);
            }
            else if (command == "remove") {
                remove(element);
            }
            else if (command == "check") {
                cout << check(element) << '\n';
            }
            else if (command == "toggle") {
                toggle(element);
            }
        }
    }
}

int main() {
    init();
    simulate();
    return 0;
}
