#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size;

    // 1.获取用户自定义的数组大小
    cout << "请输入你想要的元素个数：";
    cin >> size;

    // 2.声明一个指定大小的 vector
    vector<int> numbers(size);

    // 3.使用 for 循环逐个获取用户输入的数值
    cout << "请逐个输入 " << size << " 个整数：" << endl;
    for (int i = 0; i < size; i++) {
        cout << "请输入第 " << i + 1 << " 个数：";
        cin >> numbers[i];
    }

    // 4.打印数组，验证数值是否正确
    cout << "你输入的数组元素是：" << endl;
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
