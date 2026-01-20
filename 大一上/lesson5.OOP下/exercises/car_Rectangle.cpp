#include <iostream>
#include <string>
using namespace std;

class Rectangle {
private:
    int width;
    int height;

public:
    Rectangle() {
        width = 0;
        height = 0;
    }

    Rectangle(int _width, int _height) {
        width = _width;
        height =_height;
    }

    int getWidth() {
        return width;
    }

    int getHeight() {
        return height;
    }

    void setWidth(int w) {
        width = w;
    }

    void setHeight(int h) {
        height = h;
    }

    int calculateArea() {
        return width * height;
    }
};

int main() {
    Rectangle r1;
    r1.setWidth(5);
    r1.setHeight(10);
    cout << "r1 的面积是：" << r1.calculateArea() << endl;

    Rectangle r2(8, 6);
    cout << "r2 的面积是：" << r2.calculateArea() << endl;
    
    return 0;
}