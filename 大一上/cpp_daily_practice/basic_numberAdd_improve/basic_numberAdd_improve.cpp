#include <iostream>
using namespace std;

int main() {
    int number;
    int sum = 0;

    cout << "请输入一个整数：";
    cin >> number;

    int originalNumber = number;

    if (number < 0) {
        number = -number;
    }

    int temp = number;
    while (temp != 0) {
        int digit = temp % 10;
        sum += digit;
        temp /= 10;

        cout << "当前数字：" << digit << ", 当前总和：" << sum << endl;
    }

    if (originalNumber < 0) {
        sum = -sum;
    }

    cout << "数字 " << originalNumber << " 的各位数值之和为：" << sum << endl;

    return 0;
}
