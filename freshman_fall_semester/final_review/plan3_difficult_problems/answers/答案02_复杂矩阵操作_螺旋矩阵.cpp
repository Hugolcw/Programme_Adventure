#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int matrix[105][105] = {0};  // 初始化为0，表示未填充
    
    // 方向数组：右、下、左、上
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    
    int x = 0, y = 0;  // 当前位置
    int dir = 0;       // 当前方向（0=右）
    
    for (int num = 1; num <= n * n; num++) {
        matrix[x][y] = num;
        
        // 计算下一个位置
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        // 检查下一个位置是否有效（在范围内且未填充）
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || matrix[nx][ny] != 0) {
            // 改变方向
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        
        x = nx;
        y = ny;
    }
    
    // 输出矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    
    return 0;
}

