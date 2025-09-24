#include <iostream>
using namespace std;

void swapByPointer(int* x, int* y);
void swapByReference(int& x, int& y);

int main() {
    int a, b;
    int *ptr1 = &a, *ptr2 = &b;

    cout << "输入第一个数：";
    cin >> a;

    cout << "输入第二个数：";
    cin >> b;

    swapByPointer(ptr1, ptr2);
    cout << "交换后：a = " << a << " ,b =" << b << endl;

    swapByReference(a, b);
    cout << "交换后：a = " << a << " ,b =" << b << endl;

    return 0;
}

void swapByPointer(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swapByReference(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}