#include <iostream>
#include <string>
using namespace std;

int main() {
    string A;
    long long B;
    
    // 输入检查
    if (!(cin >> A >> B)) return 0;
    
    string Q; // 定义商的变量名为 Q
    long long R = 0;
    
    for (int i = 0; i < A.size(); i++) {
        int a = A[i] - '0';
        R = R * 10 + a;
        
        long long digit = R / B;
        R = R % B;
        
        // 使用 Q 而不是 O
        if (Q.length() > 0 || digit != 0) {
            Q += (digit + '0');
        }
    }
    
    // 使用 Q 而不是 O
    if (Q.empty()) {
        Q = "0";
    }
    
    // 使用 Q 而不是 O
    cout << Q << " " << R << endl;
    
    return 0;
}