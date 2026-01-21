#include <iostream>
using namespace std;

const int N = 105;

struct Point {
    int x, y;
};

int bfs(int maze[][N], int n, int m) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    Point q[N * N];
    int visited[N][N] = {0};
    int dist[N][N] = {0};
    int head = 0, tail = 0;
    
    q[tail++] = {0, 0};
    visited[0][0] = 1;
    dist[0][0] = 0;
    
    while (head < tail) {
        Point cur = q[head++];
        
        if (cur.x == n - 1 && cur.y == m - 1) {
            return dist[cur.x][cur.y];
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                maze[nx][ny] == 0 && visited[nx][ny] == 0) {
                visited[nx][ny] = 1;
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                q[tail++] = {nx, ny};
            }
        }
    }
    
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int maze[N][N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }
    
    cout << bfs(maze, n, m) << endl;
    
    return 0;
}

