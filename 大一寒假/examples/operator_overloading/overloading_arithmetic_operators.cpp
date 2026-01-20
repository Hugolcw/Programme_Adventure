#include <iostream>

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    // 重载 + 运算符
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
    
    // 重载 - 运算符
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }
    
    // 重载 += 运算符
    Point& operator+=(const Point& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    
    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Point p1(3, 4);
    Point p2(1, 2);
    
    Point p3 = p1 + p2;  // 使用重载的 + 运算符
    p3.print();  // 输出: (4, 6)
    
    Point p4 = p1 - p2;  // 使用重载的 - 运算符
    p4.print();  // 输出: (2, 2)
    
    p1 += p2;    // 使用重载的 += 运算符
    p1.print();  // 输出: (4, 6)
}
