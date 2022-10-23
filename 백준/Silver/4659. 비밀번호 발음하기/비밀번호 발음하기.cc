// 문제 링크: https://www.acmicpc.net/problem/4659
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<char> vowels;

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');
}

bool isVowel(char input) {
    if (vowels.find(input) == vowels.end()) return false;
    return true;
}

string judge (string &input) {
    bool hasAtLeastOneVowels = false;
    int continuousVowelCount = 0;
    int continuousConsonantCount = 0;
    bool hasUnacceptableCondition = false;
    
    for (int i = 0; i < input.size(); i++) {
        if (isVowel(input[i])) hasAtLeastOneVowels = true;
        if (i == 0) continue;
        if (input[i] == input[i - 1]) {
            if (input[i] != 'e' && input[i] != 'o') {
                hasUnacceptableCondition = true;
                break;
            }
        }
        if (i == 1) continue;
        if ((isVowel(input[i]) && isVowel(input[i - 1]) && isVowel(input[i - 2]))
            || (!isVowel(input[i]) && !isVowel(input[i - 1]) && !isVowel(input[i - 2]))) {
            hasUnacceptableCondition = true;
            break;
        }
    }
    
    if (!hasAtLeastOneVowels || hasUnacceptableCondition) {
        return "<" + input + "> is not acceptable.";
    }
    else {
        return "<" + input + "> is acceptable.";
    }
}

int main() {
    init();
    while(1) {
        string input; cin >> input;
        if (input == "end") break;
        cout << judge(input) << '\n';
    }
}
