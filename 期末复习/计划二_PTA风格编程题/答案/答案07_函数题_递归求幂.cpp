#include <iostream>
#include <iomanip>
using namespace std;

double power(double x, int n) {
    if (n == 0) {
        return 1.0;
    }
    
    if (n > 0) {
        return x * power(x, n - 1);
    } else {
        return 1.0 / power(x, -n);
    }
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        double x;
        int n;
        cin >> x >> n;
        
        double result = power(x, n);
        cout << fixed << setprecision(3) << result << endl;
    }
    
    return 0;
}

