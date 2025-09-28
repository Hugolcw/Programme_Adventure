#include <iostream>
using namespace std;

// 矩形面积函数，height有默认值10.0
double calculateRectangleArea(double width, double height = 10.0) {
    return width * height;
}

int main() {
    //使用默认高度
    cout << "矩形面积（5*10）:" << calculateRectangleArea(5.0) << endl;
    //使用自定义高度
    cout << "矩形面积（5*8）：" << calculateRectangleArea(5.0, 8.0) << endl;

    return 0;
}
