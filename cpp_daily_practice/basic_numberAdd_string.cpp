#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int sum = 0;

    cout << "请输入一个整数：";
    cin >> input;

    bool isNegative = (input[0] == '-');
    int startIndex = isNegative ? 1 : 0;

    for (int i = startIndex; i < input.length(); i++) {
        int digit = input[i] - '0';
        sum += digit;
    }

    if (isNegative) {
        sum = -sum;
    }

    cout << "数字 " << input << " 的各位数字之和为：" << sum << endl;

    return 0;
}
