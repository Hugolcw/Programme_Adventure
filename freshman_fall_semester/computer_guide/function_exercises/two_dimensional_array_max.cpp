#include <iostream>

using namespace std;
const int N=10;

int fun(int array[][N],int n,int m) ; 
main()
{
  int a[N][N],n,m,i,j,max;
  cin>>n>>m;
  
  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      cin>>a[i][j];   
 max=fun(a,n,m);
 cout<<max;
}

/* 请在这里填写答案 */
int fun(int array[][N], int n, int m) {
    int max = array[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (max < array[i][j]) {
                max = array[i][j];
            }
        }
    }
    return max;
}