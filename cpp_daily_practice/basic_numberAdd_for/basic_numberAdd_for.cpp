#include <iostream>
using namespace std;

int main() {
    int number;
    int sum = 0;

    cout << "请输入一个整数：";
    cin >>number;

    int originalNumber = number;

    for (; number != 0; number /= 10) {
        sum += number % 10;
    }

    cout << "数字 " << originalNumber << " 的各位数字之和为: " << sum << endl;
    
    return 0;
}
