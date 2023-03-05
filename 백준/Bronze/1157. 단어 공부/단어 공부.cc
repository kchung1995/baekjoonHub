#include <iostream>
#include <string>
using namespace std;

int main() {
    
    int alphabet[26] = {0, };
    string input;
    
    cin >> input;
    
    for (int i = 0; i < input.size(); i++) {
        if ((int)input[i] - 97 < 0) //대문자임을 의미 {
        {
            int temp = input[i] - 65;
            alphabet[temp]++;
        }
        else {                  //소문자
            int temp = input[i] - 97;
            alphabet[temp]++;
        }
    }

    
    int max = 0;
    int max_counter = 0;
    int trigger = 1;
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] > max) {
            max = alphabet[i];
            max_counter = i;
            trigger = 0;
        }
        else if (alphabet[i] == max)
            trigger = 1;
    }
    
    if (trigger == 1)
        cout << '?';
    else
        cout << (char)(max_counter + 65);

    
    
    return 0;
}
