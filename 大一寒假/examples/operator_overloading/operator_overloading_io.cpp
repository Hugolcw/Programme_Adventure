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
    
    // 重载 == 运算符
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    
    // 重载 != 运算符
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }
    
    // 重载 < 运算符（用于排序）
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    
    // 友元函数：重载 << 运算符（输出）
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
    
    // 友元函数：重载 >> 运算符（输入）
    friend std::istream& operator>>(std::istream& is, Point& p) {
        std::cout << "请输入 x 和 y 坐标: ";
        is >> p.x >> p.y;
        return is;
    }
    
    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    std::cout << "=== 算术运算符重载示例 ===" << std::endl;
    Point p1(3, 4);
    Point p2(1, 2);
    
    Point p3 = p1 + p2;  // 使用重载的 + 运算符
    std::cout << "p1 + p2 = " << p3 << std::endl;
    
    Point p4 = p1 - p2;  // 使用重载的 - 运算符
    std::cout << "p1 - p2 = " << p4 << std::endl;
    
    p1 += p2;    // 使用重载的 += 运算符
    std::cout << "p1 += p2, p1 = " << p1 << std::endl;
    
    std::cout << "\n=== 比较运算符重载示例 ===" << std::endl;
    Point p5(3, 4);
    Point p6(3, 4);
    Point p7(1, 2);
    
    std::cout << "p5 == p6: " << (p5 == p6) << std::endl;
    std::cout << "p5 != p7: " << (p5 != p7) << std::endl;
    std::cout << "p7 < p5: " << (p7 < p5) << std::endl;
    
    std::cout << "\n=== 输入输出运算符重载示例 ===" << std::endl;
    std::cout << "p5 = " << p5 << std::endl;
    
    // 注释掉输入部分，避免程序等待用户输入
    // Point p8;
    // std::cin >> p8;
    // std::cout << "输入的点: " << p8 << std::endl;
    
    return 0;
}