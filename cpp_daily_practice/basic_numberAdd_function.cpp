#include <iostream>
using namespace std;

int sumOfDigit(int num);

int main() {
    int number;

    cout << "请输入一个整数：";
    cin >> number;

    int result = sumOfDigit(number);

    cout << "数字 " << number << " 的各位数字之和为：" << result << endl;

    return 0;
}

// 函数定义
int sumOfDigit(int num) {
    int sum = 0;
    int n = (num <0) ? -num : num;

    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }

    return (num < 0) ? -sum : sum;
}
