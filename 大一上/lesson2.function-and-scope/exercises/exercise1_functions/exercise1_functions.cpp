#include <iostream>
using namespace std;

// 函数声明
double calculateArea(double radius) {
    const double PI = 3.1415926535;
    return PI * radius * radius;
}

double calculateCircumference(double radius) {
    const double PI = 3.1415926535;
    return PI * radius * 2;
}

int main() {
    double radius = 5.0;

    //调用函数
    cout << "半径：" << radius << endl;
    cout << "面积：" << calculateArea(radius) << endl;
    cout << "周长：" << calculateCircumference(radius) << endl;

    return 0;
}
