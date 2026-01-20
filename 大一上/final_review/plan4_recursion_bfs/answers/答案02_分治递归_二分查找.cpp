#include <iostream>
using namespace std;

int binarySearch(int a[], int left, int right, int target);

int main() {
    int n, target;
    cin >> n >> target;
    
    int a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << binarySearch(a, 0, n - 1, target) << endl;
    
    return 0;
}

int binarySearch(int a[], int left, int right, int target) {
    // 终止条件1：查找区间为空
    if (left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;  // 避免溢出
    
    // 终止条件2：找到目标值
    if (a[mid] == target) {
        return mid;
    }
    
    // 递归关系：在左半部分或右半部分查找
    if (target < a[mid]) {
        return binarySearch(a, left, mid - 1, target);
    } else {
        return binarySearch(a, mid + 1, right, target);
    }
}

