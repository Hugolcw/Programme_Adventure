#include <iostream>
using namespace std;

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(double a, double b);

int main() {
    int num1, num2;
    char operation;
    
    cout << "请输入第一个数：";
    cin >> num1;

    cout << "请输入运算符(+, -, *, /)：";
    cin >> operation;

    cout << "请输入第二个数：";
    cin >> num2;

    if (operation = '+') {
         num1 + num2;
    } else if (operation = '-') {
        return num1 - num2;
    } else if (operation = '*') {
        return num1 * num2;
    } else if (operation = '/') {
        return num1 / num2;
    }
