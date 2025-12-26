#include <iostream>

using namespace std;

int main() {
    // 1. 定义 n 为 long long 类型，防止输入和计算溢出
    long long n;
    
    // 2. 读取输入
    if (cin >> n) {
        // 3. 根据推导的公式计算基数 k
        // 当 n=1, k=1; n=2, k=1; n=3, k=2; n=4, k=2...
        // 这正是 (n + 1) / 2 的效果
        long long k = (n + 1) / 2;
        
        // 4. 输出 k 的平方
        cout << k * k << endl;
    }
    
    return 0;
}