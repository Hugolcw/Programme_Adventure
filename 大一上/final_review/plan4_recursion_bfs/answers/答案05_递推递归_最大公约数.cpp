#include<iostream>
using namespace std;

int gcd(int a, int b);

int main() {
    int a, b;
    while(cin >> a >> b) {
        cout << gcd(a, b) << endl;
    }
    return 0;
}

int gcd(int a, int b) {
    // 终止条件：b == 0，a就是最大公约数
    if (b == 0) {
        return a;
    }
    
    // 递归关系：gcd(a, b) = gcd(b, a % b)
    return gcd(b, a % b);
}

