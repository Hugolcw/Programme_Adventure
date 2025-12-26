#include <iostream>
using namespace std;

int main() {
    char c;
    int n;
    cin >> c >> n;

    int current_pos = c - 'A';

    int new_pos = (current_pos + n % 26 + 26) % 26;

    char result = 'A' + new_pos;

    cout << result << endl;
    
    return 0;
}

