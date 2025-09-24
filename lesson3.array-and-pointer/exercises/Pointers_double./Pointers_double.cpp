#include <iostream>
using namespace std;

int main() {
    int x;
    int* ptr = &x;

    cout << "输入一个整数：";
    cin >> x;

    *ptr *= 2;

    cout << "最终值为：" << *ptr << endl;

    return 0;

}