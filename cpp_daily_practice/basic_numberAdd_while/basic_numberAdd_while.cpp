#include <iostream>
using namespace std;

int main() {
    int number;
    int sum = 0; //初始化总和为0

    cout << "请输入一个整数：";
    cin >> number;

    int originalNumber = number;

    while (number != 0) {
        int digit = number % 10;
        sum += digit;
        number = number / 10;
        cout << "当前数字：" << digit << ", 当前总和：" << sum << endl;
    }

    cout << "数字 " << originalNumber << " 的各位数字之和为：" << sum << endl;

    return 0;
}
