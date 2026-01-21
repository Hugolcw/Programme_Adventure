#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    char oldChar, newChar;
    cin >> oldChar >> newChar;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == oldChar) {
            s[i] = newChar;
        }
    }
    
    cout << s << endl;
    
    return 0;
}

