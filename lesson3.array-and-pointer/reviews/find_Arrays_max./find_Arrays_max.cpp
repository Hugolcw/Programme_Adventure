#include <iostream>
#include <vector>
using namespace std;

int* findMax(vector<int>& arr);

int main() {
    int size;

    cout << "请输入数组大小：";
    cin >> size;

    vector<int> numbers(size);
    cout << "请逐个输入 " << size << " 个整数" << endl;
    for (int i = 0; i < size; i++) {
        cout << "请输入第 " << i + 1 << " 个整数:";
        cin >> numbers[i];
    } 
    
    int* result_ptr;

    result_ptr = findMax(numbers);

    cout << "数组中最大的值是：" << *result_ptr << endl;

    return 0;
}

int* findMax(vector<int>& arr) {
    // 1.声明一个指针，并假设第一个元素是最大值
    int* maxPtr = &arr[0];

    // 2.从第二个元素开始遍历数组
    // 所以 for 循环从 i = 1 开始
    for (int i = 1; i < arr.size(); i++) {
        // 3.比较当前元素的值和目前的最大值
        // *maxPtr 是解引用，获取 maxPtr 指向的值
        if (arr[i] > *maxPtr) {
            // 4.如果当前值更大，更新 maxPtr，让它指向当前元素
            maxPtr = &arr[i];    
        }
    }

    // 5.循环结束，返回 maxPtr
    return maxPtr;

}