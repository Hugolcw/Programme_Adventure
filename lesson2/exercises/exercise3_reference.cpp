#include <iostream>
using namespace std;

//交换函数
void swapNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;

    cout << "交换前：x=" << x << ", y=" << y << endl;
    swapNumbers(x,y);
    cout << "交换后：x=" << x << ", y=" << y << endl;

    return 0;
}
