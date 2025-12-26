#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int digit_count = 0;
    int space_count = 0;
    int letter_count = 0;
    int other_count = 0;

    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            digit_count++;
        }
        else if (isalpha(s[i])) {
            letter_count++;
        }
        else if (s[i] == ' ') {
            space_count++;
        }
        else {
            other_count++;
        }
    }

    cout << "数字:" << digit_count << endl;
    cout << "空格:" << space_count << endl;
    cout << "字母:" << letter_count << endl;
    cout << "其他字符:" << other_count << endl;

    return 0;
}
