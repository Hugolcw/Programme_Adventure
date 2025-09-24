#include <iostream>
using namespace std;

void swapNumber(int& x, int& y);

int main() {
    int a, b;

    cout << "请输入第一个值：";
    cin >> a;
    cout << "请输入第二个值：";
    cin >> b;

    cout << "交换前: a = " << a << "，b = " << b << endl;

    swapNumber(a, b);

    cout << "交换后：a = " << a << "，b = " << b << endl;

    return 0;
}

void swapNumber(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}