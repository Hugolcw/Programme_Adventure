#include <iostream>

// 长度单位用户自定义字面量示例：
//  - 1.5_km 表示 1500.0 米
//  - 30_cm  表示 0.30 米
// 使用 double 存储「米」这一统一单位。

constexpr long double operator"" _km(long double value) {
    return value * 1000.0L;
}

constexpr long double operator"" _m(long double value) {
    return value;
}

constexpr long double operator"" _cm(long double value) {
    return value / 100.0L;
}

constexpr long double operator"" _mm(long double value) {
    return value / 1000.0L;
}

double add_distance(long double a, long double b) {
    return a + b;
}

// 练习建议：
// 1. 根据下面的示例，自己增加一个 _mm（毫米）字面量。
// 2. 写一个函数 double add_distance(long double a, long double b)，
//    让 main 里可以统一用「米」作为返回值进行相加与打印。
// 3. 自己设计至少 3 组不同的测试数据，验证是否符合直觉。

int main() {
    long double d1 = 1.5_km;   // 1500 m
    long double d2 = 300.0_m;  // 300 m
    long double d3 = 50.0_cm;  // 0.5 m
    long double d4 = 10.0_mm;  // 0.01 m
    long double total = d1 + d2 + d3 + d4;

    std::cout << "d1 = 1.5_km = " << static_cast<double>(d1) << " m\n";
    std::cout << "d2 = 300.0_m = " << static_cast<double>(d2) << " m\n";
    std::cout << "d3 = 50.0_cm = " << static_cast<double>(d3) << " m\n";
    std::cout << "d4 = 10.0_mm = " << static_cast<double>(d4) << " m\n";
    std::cout << "total = " << static_cast<double>(total) << " m\n";

    return 0;
}

