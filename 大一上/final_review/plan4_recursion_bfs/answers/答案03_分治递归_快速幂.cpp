#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long power(long long a, long long n);

int main() {
    long long a, n;
    cin >> a >> n;
    cout << power(a, n) << endl;
    return 0;
}

long long power(long long a, long long n) {
    // 终止条件
    if (n == 0) {
        return 1;
    }
    
    // 递归关系：计算a^(n/2)
    long long half = power(a, n / 2);
    
    if (n % 2 == 0) {
        // n是偶数：a^n = (a^(n/2))^2
        return (half * half) % MOD;
    } else {
        // n是奇数：a^n = a × (a^(n/2))^2
        return (a * half * half) % MOD;
    }
}

