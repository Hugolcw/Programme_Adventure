#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        int sum = 0;
        for (int j = 1; j < n; j++) {
            if (n % j == 0) {
                sum += j;
            }
        }
        
        if (sum == n) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    
    return 0;
}

