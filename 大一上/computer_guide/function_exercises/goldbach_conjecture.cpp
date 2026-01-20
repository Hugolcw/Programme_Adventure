在这里给出函数被调用进行测试的例子：
#include <iostream>
#include <cmath>
using namespace std;

void   fun(  int m,  int n );

int main()
{
  int  m,n;
  cin>>m>>n;
  fun(m,n);
  return 0;
}


/* 请在这里填写答案 */
int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i ==0) return 0;
    }
    return 1;
}

void fun(int m, int n) {
    if (m > n) {
        int temp = m;
        m = n;
        n = temp;
    }

    for (int i = m; i <= n; i++) {
        if (i > 2 && i % 2 == 0) {
            for (int j = 2; j <= i / 2; j++) {
                if (isPrime(j) && isPrime(i - j)) {
                    cout << i << "=" << j << "+" << i - j << endl;
                    break;
                }
            }
        }
    }
}