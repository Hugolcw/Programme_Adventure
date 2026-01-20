#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int matrix[105][105] = {0};
    
    // 方法一：方向数组法（与螺旋矩阵相同）
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    
    int x = 0, y = 0;
    int dir = 0;
    
    for (int num = 1; num <= n * n; num++) {
        matrix[x][y] = num;
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || matrix[nx][ny] != 0) {
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

