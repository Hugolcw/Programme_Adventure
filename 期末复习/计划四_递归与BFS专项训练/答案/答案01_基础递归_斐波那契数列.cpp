#include <iostream>
using namespace std;

long long fib(int n);

int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}

long long fib(int n) {
    // 终止条件
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // 递归关系：F(n) = F(n-1) + F(n-2)
    return fib(n-1) + fib(n-2);
}

