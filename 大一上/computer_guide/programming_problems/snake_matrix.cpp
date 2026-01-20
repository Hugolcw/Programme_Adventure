#include <iostream>
#include <algorithm> // 用于 max 和 min 函数

using namespace std;

int main() {
    int n;
    // 读取阶数
    if (!(cin >> n)) return 0;

    // 定义二维数组，范围 1-100，所以 105 足够
    int matrix[105][105];
    
    int value = 1; // 要填充的数字，从 1 开始

    // 遍历所有对角线，sum 为行下标与列下标之和
    // sum 的范围是 0 到 2*n - 2
    for (int sum = 0; sum <= 2 * n - 2; ++sum) {
        
        // 计算当前对角线行下标 row 的有效范围
        // row 至少为 0
        // row 至多为 n-1
        // 同时 col = sum - row 也必须在 [0, n-1] 范围内
        // 推导：row = sum - col => 当 col 最大(n-1)时 row 最小 => row >= sum - (n-1)
        //       当 col 最小(0)时 row 最大 => row <= sum
        
        int row_start = max(0, sum - n + 1);
        int row_end = min(sum, n - 1);

        // 判断填充方向
        if (sum % 2 == 0) {
            // sum 为偶数：向左下填充（行号增大）
            // 循环从最小行号到最大行号
            for (int i = row_start; i <= row_end; ++i) {
                int j = sum - i;
                matrix[i][j] = value++;
            }
        } else {
            // sum 为奇数：向右上填充（行号减小）
            // 循环从最大行号到最小行号
            for (int i = row_end; i >= row_start; --i) {
                int j = sum - i;
                matrix[i][j] = value++;
            }
        }
    }

    // 输出矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j];
            // 如果不是一行的最后一个数，输出空格
            if (j < n - 1) {
                cout << " ";
            }
        }
        // 每一行输出结束后换行
        cout << endl;
    }

    return 0;
}