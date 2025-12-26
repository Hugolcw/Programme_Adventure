#include <iostream>
using namespace std;

int arr[10];      // 存储当前排列
bool used[10];    // 标记数字是否已使用

void permute(int pos, int n);

int main() {
    int n;
    cin >> n;
    
    // 初始化used数组
    for (int i = 1; i <= n; i++) {
        used[i] = false;
    }
    
    permute(0, n);
    
    return 0;
}

void permute(int pos, int n) {
    // 终止条件：已经放置了n个数字
    if (pos == n) {
        // 输出当前排列
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << " ";
            cout << arr[i];
        }
        cout << endl;
        return;
    }
    
    // 递归关系：尝试放置所有未使用的数字
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            // 尝试：放置数字i
            arr[pos] = i;
            used[i] = true;
            
            // 递归：处理下一个位置
            permute(pos + 1, n);
            
            // 回溯：恢复状态
            used[i] = false;
        }
    }
}

