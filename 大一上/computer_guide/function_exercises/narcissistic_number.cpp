#include <iostream>
using namespace std;

bool narcissistic(int number);

int main()
{

  int m;

  cin>>m;
  if(narcissistic(m)==true)
       cout<<m<<" is a narcissistic number.";
  else
       cout<<m<<" is not a narcissistic number.";

 return 0;
}

/* 请在这里填写答案 */
bool narcissistic(int number) {
    int temp = number;
    int sum = 0;

    while(temp > 0) {
        int digit = temp % 10;
        sum += digit * digit * digit;
        temp /= 10;
    }

    if (sum == number) {
        return true;
    } else {
        return false;
    }
}