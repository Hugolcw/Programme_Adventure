#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size;

    cout << "请输入数组的大小：";
    cin >> size;

    vector<int> numbers(size);

    cout << "请逐个输入 " << size << " 个整数：" << endl;
    for (int i = 0; i < size; i++) {
        cout << "请输入第 " << i + 1 << " 个数：";
        cin >> numbers[i];    
    }
    
    int even_count = 0;

    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 == 0) {
            even_count++;
        }
    }

    cout << "数组中的偶数个数是：" << even_count << endl;

    return 0;
}