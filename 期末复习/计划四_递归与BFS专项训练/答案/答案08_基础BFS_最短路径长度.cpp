#include <iostream>
using namespace std;

const int N = 105;

int bfs(int a[][N], int n, int start, int end) {
    int q[N * N];
    int visited[N] = {0};
    int dist[N] = {0};
    int head = 0, tail = 0;

    q[tail++] = start;
    visited[start] = 1;
    dist[start] = 0;

    while (head < tail) {
        int cur = q[head++];

        if (cur == end) {
            return dist[cur];
        }

        for (int i = 1; i <= n; i++) {
            if (a[cur][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                dist[i] = dist[cur] + 1;
                q[tail++] = i;
            }
        }
    }

    return -1;
}

int main() {
    int n, start, end;
    cin >> n >> start >> end;
    
    int a[N][N];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    
    cout << bfs(a, n, start, end) << endl;
    
    return 0;
}

