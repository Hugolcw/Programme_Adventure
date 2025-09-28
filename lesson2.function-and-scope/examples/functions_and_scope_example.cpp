#include <iostream>

// 1.函数声明
void printMessage();
void changeValue(int& num);
int add(int a, int b);
double add(double a, double b);

// 2.全局变量（尽量避免）
int globalVar = 100;

int main() {
    // 局部变量
    int localVar = 10;

    std::cout << "Local variable:" << localVar << std::endl;
    std::cout << "Global variable:" << globalVar << std::endl;

    // 3.值传递示例
    int x = 5;
    std::cout << "Before value change (x):" << x << std::endl;
    // 值传递
    add(x, 10);
    std::cout << "After value change (x):" << x << " (unmodified)" << std::endl;

    // 4.引用传递示例
    int y = 5;
    std::cout << "Before reference change (y):" << y << std::endl;
    // 引用传递
    changeValue(y);
    std::cout << "After reference change(y):" << y << " (modified)" << std::endl;

    // 5.函数重载示例
    int sumInt = add(5, 10);
    double sumDouble = add(5.5, 10.5);
    std::cout << "Sum of intrgers:" << sumInt << std::endl;
    std::cout << "Sum of doubles:" << sumDouble << std::endl;

    // 6.命名空间示例
    // 可以显式使用 std::
    std::cout << "Using std namespace explicitly." << std::endl;
    // 也可以通过 using 声明简化
    using std::cout;
    using std::endl;
    cout << "Using std::cout and std::endl with using declaration." << endl;

    return 0;
}

// 函数定义
void printMaesssge() {
    std::cout << "This is a function." << std::endl;
}

void changeValue(int& num) {
    num = num + 10;
}

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}
    
