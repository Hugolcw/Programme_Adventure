#include <iostream>
int findMax(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    // 1.声明变量，用于存储输入
    int num1, num2, num3;

    // 2.提示输入
    std::cout << "请输入第一个整数：";
    // 3.使用 cin 从键盘中读取数据并存入 num1
    std::cin >> num1;

    std::cout << "请输入第二个整数：";
    std::cin >> num2;
    std::cout << "请输入第三个整数：";
    std::cin >> num3;

    // 4.调用函数并打印结果
    int maxValue = findMax(num1, num2, num3);
    std::cout << "这三个数中最大的是：" << maxValue << std::endl;

    return 0;
}
