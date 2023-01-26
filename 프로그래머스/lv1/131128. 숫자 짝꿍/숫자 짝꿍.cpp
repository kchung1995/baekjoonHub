#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    unordered_map<char, int> xCount;
    unordered_map<char, int> yCount;
    
    for (auto &i : X) {
        xCount[i]++;
    }
    for (auto &i : Y) {
        yCount[i]++;
    }
    
    for (int i = 0; i <= 9; i++) {
        char temp = i + '0';
        while(xCount[temp] > 0 && yCount[temp] > 0) {
            answer += temp;
            xCount[temp]--;
            yCount[temp]--;
        }
    }
    
    if (answer == "") return "-1";
    sort(answer.begin(), answer.end(), greater<char>());
    if (answer[0] == '0' && answer.back() == '0') return "0";
    return answer;
}