#include <iostream>
using namespace std;

void swapMax(int *arr, int n) {
    if (n <= 0) return;
    
    // 找到最大值的索引
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    
    // 交换第一个元素和最大值
    if (maxIndex != 0) {
        int temp = arr[0];
        arr[0] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        int arr[105];
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        
        swapMax(arr, n);
        
        // 输出数组
        for (int j = 0; j < n; j++) {
            cout << arr[j];
            if (j < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}

