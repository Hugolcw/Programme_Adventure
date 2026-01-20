#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;

    cout << "请输入第一个数：";
    cin >> num1;

    cout << "请输入运算符（+，-，*，/）：";
    cin >> op;

    cout << "请输入第二个数：";
    cin >> num2;

    switch (op) {
        case '+':
            cout << "结果：" << num1 + num2 << endl;
            break;
        case '-':
            cout << "结果：" << num1 - num2 << endl;
            break;
        case '*':
            cout << "结果：" << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "结果：" << num1 / num2 << endl;
            } else {
                cout << "错误：除数不能为0！" << endl;
            }
            break;
        default:
            cout << "错误：不支持的运算符！" << endl;
        }
    return 0;
}
