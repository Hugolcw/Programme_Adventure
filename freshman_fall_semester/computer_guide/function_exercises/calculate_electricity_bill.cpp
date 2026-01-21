#include <iostream>
using namespace std;

double getCost(double x);

int main()
{

  double x,y;

  cin>>x;
  y=getCost(x);
  cout<<"cost="<<y;
  return 0;

}


/* 请在这里填写答案 */
double getCost(double x) {
    if (x <= 0) {
        return 0;
    } else if (x <= 50) {
        return x * 0.53;
    } else {
        return 26.5 + (x - 50) * 0.58;
    }
}