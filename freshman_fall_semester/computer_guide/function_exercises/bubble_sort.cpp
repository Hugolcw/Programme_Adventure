#include<iostream>
using namespace std;

void bubbleSort ( int a[ ], int n );

//输入n及n个整数，对n个整数非递减序排序并输出，处理到文件尾 
int main() {
    int n;
    while(cin>>n) {
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        bubbleSort(a, n);
        cout<<a[0];
        for(int i=1;i<n;i++) cout<<" "<<a[i];
        cout<<endl; 
    }    
    return 0;
}

//请在此处填写答案
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}