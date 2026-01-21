#include <iostream>
using namespace std;

void passByValue(int number);
void passByReference(int& number);

int main() {
    int originalNumber;
    cout << "请输入初始值：" ;
    cin >> originalNumber;
    
    cout << "初始状态为：" << originalNumber << endl;
    cout << endl;

    // 第一次调用：值传递
    cout << "调用 passByValue 函数" << endl;
    passByValue(originalNumber);
    cout << "调用 passByValue 函数后，originalNumber的值是：" << originalNumber << endl;
    cout << endl;

    // 第二次调用：引用传递
    cout << "调用 passByReference 函数" << endl;
    passByReference(originalNumber);
    cout << "调用 psaaByReference 函数后，originalNumber的值是：" << originalNumber << endl;
    cout << endl;

    return 0;
}

// 函数定义：值传递
void passByValue(int number) {
    cout << "在 passByValue 函数内部，参数 number 的值是：" << number << endl;
    number = 99;
    cout << "在 passByValue 函数内部，将 number 改为：" << number << endl;
}

void passByReference(int& number) {
    cout << "在 passByReference 函数内部，参数 number 的值是：" << number << endl;
    number = 99;
    cout << "在 passByReference 函数内部，将 number 改为：" << number << endl;
}