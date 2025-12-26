#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    char c;
    getline(cin, s);
    cin >> c;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != c) {
            cout << s[i];
        }
    }

    cout << endl;
    
    return 0;
}