#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        if (n == 1) {
            cout << 1 << endl;
        } else if (n == 2) {
            cout << 2 << endl;
        } else {
            int a = 1, b = 2;
            for (int j = 3; j <= n; j++) {
                int c = a + b;
                a = b;
                b = c;
            }
            cout << b << endl;
        }
    }
    
    return 0;
}

