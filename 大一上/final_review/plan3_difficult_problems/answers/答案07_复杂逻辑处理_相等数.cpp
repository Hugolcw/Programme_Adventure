#include <iostream>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    bool found = false;

    for (int d = 1; d <= 9; d++) {
        long long num = d;
        
        while (num <= b) {
            if (num >= a) {
                if (found) cout << " ";
                cout << num;
                found = true;
            }

            num = num * 10 + d;
        }
    }

    if (!found) {
        cout << "none";
    }

    cout << endl;

    return 0;
}

