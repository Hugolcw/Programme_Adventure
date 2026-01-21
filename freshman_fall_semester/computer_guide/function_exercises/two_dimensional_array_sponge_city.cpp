#include <iostream>
using namespace std;
const int N=21;

/* 请在这里填写答案 */
int test(int a[][N], int start, int end) {
    int q[N + 5];
    int visited[N] = {0};
    int head = 0, tail = 0;

    q[tail++] = start;
    visited[start] =  1;

    while (head < tail) {
        int cur = q[head++];

        if (cur == end) return 1;

        for (int i = 1;i < N; i++) {
            if (a[cur][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                q[tail++] = i;
            }
        }
    }

    return 0;
}

int main()
{
  int a[N][N]={0}, n, m, i, j, k;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>j>>k;
    a[j][k]=a[k][j]=1;
  }
  cin>>m;
  for(i=0;i<m;i++){
    cin>>j>>k;
    cout<<j<<'-'<<k<<' ';
    if(test(a, j, k)) cout<<"connected"<<endl; else cout<<"disconnected"<<endl;
  }    
  return 0;
}


