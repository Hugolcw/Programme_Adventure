#include <iostream>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    
    int a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            pos = i + 1;  // 位置从1开始
            break;
        }
    }
    
    cout << pos << endl;
    
    return 0;
}

