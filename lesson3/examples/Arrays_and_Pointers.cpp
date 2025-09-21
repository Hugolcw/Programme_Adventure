#include <iostream>
using namespace std;

int main() {
    // 1.数组
    int numbers[5] = {1, 2, 3, 4, 5};
    cout << "第一个元素：" << numbers[0] << endl;
    cout << "第三个元素：" << numbers[2] << endl;
    cout << endl;

    // 2.指针
    int value;
    int* ptr = &value;
    
    cout << "请输入一个整数：";
    cin >> value;
    
    cout << "变量 value 的值：" << value << endl;
    cout << "变量 value 的地址：" << &value << endl;
    cout << "指针 ptr 存储的地址：" << ptr << endl;
    cout << "通过指针解引得到的值：" << *ptr << endl;
    cout << endl;

    // 3.指针与数组
    int scores[3] = {100, 200, 300};
    int*scoresPtr = scores; // 数组名就是指向第一个元素的指针
    cout << "使用数组名访问第二个元素：" << scores[1] << endl;
    cout << "使用指针算数访问第二个元素：" << *(scoresPtr + 1) << endl;

    return 0;
}