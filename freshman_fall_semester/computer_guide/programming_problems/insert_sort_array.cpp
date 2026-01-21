#include <iostream>

using namespace std;

int main() {
    int a[11] = {1, 4, 6, 9, 11, 25, 31, 46, 83, 100};

    int x;
    cin >> x;

    int i;
    
    for (i = 9; i >= 0; i--) {
        if (a[i] > x) {
            a[i + 1] = a[i]; 
        }
        else {
            break;
        }
    }

    a[i + 1] = x;

    for (int j = 0; j < 11; j++) {
        cout << a[j];
        if (j < 10) {
            cout << " ";
        }
    }
    return 0;
    
}