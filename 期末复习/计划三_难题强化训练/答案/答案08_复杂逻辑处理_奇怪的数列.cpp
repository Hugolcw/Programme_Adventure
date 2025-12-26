#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    
    // 根据规律：第n项的值是 k²，其中 k = ⌈n/2⌉ = (n+1)/2
    long long k = (n + 1) / 2;
    
    cout << k * k << endl;
    
    return 0;
}

