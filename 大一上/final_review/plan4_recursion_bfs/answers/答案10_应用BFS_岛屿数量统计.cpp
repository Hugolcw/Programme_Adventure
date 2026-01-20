#include <iostream>
using namespace std;

const int N = 105;

struct Point {
    int x, y;
};

void bfs(int grid[][N], int visited[][N], int n, int m, int startX, int startY) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    Point q[N * N];
    int head = 0, tail = 0;
    
    q[tail++] = {startX, startY};
    visited[startX][startY] = 1;
    
    while (head < tail) {
        Point cur = q[head++];
        
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                grid[nx][ny] == 1 && visited[nx][ny] == 0) {
                visited[nx][ny] = 1;
                q[tail++] = {nx, ny};
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int grid[N][N];
    int visited[N][N] = {0};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && visited[i][j] == 0) {
                bfs(grid, visited, n, m, i, j);
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}

