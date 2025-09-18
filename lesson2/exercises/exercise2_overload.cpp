#include <iostream>
using namespace std;

// double版本
double calculateArea(double radius) {
    const double PI = 3.1415926535;
    return PI * radius * radius;
}

// float版本
float calculateArea(float radius) {
    const float PI = 3.1415926535f;
    return PI * radius * radius;
}

int main() {
    double radius_d = 5.0;
    float radius_f = 5.0f;

    cout << "Double面积：" << calculateArea(radius_d) << endl;
    cout << "Float面积：" << calculateArea(radius_f) << enfl;

    return 0;
}
