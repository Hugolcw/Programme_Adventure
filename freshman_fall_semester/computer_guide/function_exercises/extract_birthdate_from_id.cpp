#include<iostream>
#include<cstring>
using namespace std;
void getBirth(char a[], char b[]);
const int N=19;

int main()
{
    char id[N],birth[9];
    cin.getline(id,N);

    getBirth(id,birth);  
    cout << birth;

    return 0;
}

/* 请在这里填写答案 */
void getBirth(char a[], char b[]) {
    for (int i = 6; i < 14; i++) {
        b[i-6] = a[i];
    }
}