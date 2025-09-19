#include <iostream>
using namespace std;

int findMax(int a, int b, int c)

int main() {
    int num1, num2 ,num3;
    
    cout << "请输入第一个数：";
    cin >> num1;
    
    cout << "请输入第二个数：";
    cin >> num2;
    
    cout << "请输入第三个数：";
    cin >> num3;

    int maxValue = findMax(num1 , num2 , num3);
    cout << "这三个数中最大的是：" << maxValue << endl;

    return 0;
}

int findMax(int a, int b, int c) {
    int maxVal = a;

    if (b >= maxVal) {
        maxVal = b;
    }

    if (c >= maxVal) {
        maxVal = c;
    }

    return maxVal;
}
