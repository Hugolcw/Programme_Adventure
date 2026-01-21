#include <iostream>
using namespace std;

int main() {
    const double PI = 3.1415926535;
    double radius = 5.0;

    double area = PI * radius * radius;
    double circumference = PI * 2 * radius;

    cout << "圆的半径" << radius << endl;
    cout << "圆的面积" << area << endl;
    cout << "圆的周长" << circumference << endl;

    return 0;
}
   
