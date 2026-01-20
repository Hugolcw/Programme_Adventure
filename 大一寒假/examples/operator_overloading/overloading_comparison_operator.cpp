#include <iostream>

class Point {
private:
    int x, y;    
public:
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
};

int main() {
    Point p1(3, 4);
    Point p2(3, 4);
    Point p3(1, 2);
    
    std::cout << (p1 == p2) << std::endl;  // 输出: 1 (true)
    std::cout << (p1 != p3) << std::endl;  // 输出: 1 (true)
    std::cout << (p3 < p1) << std::endl;   // 输出: 1 (true)
}
