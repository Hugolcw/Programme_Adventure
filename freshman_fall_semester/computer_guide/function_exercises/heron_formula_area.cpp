#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double getArea(double a, double b,double c);
bool validate(double a,double b,double c);

int main()
{

  double a,b,c;

  cin>>a>>b>>c;
  if(validate(a,b,c)==false)
     cout<<"Invalidate Triangle";
  else
     cout<<"The area is:"<<fixed<<setprecision(2)<< getArea(a,b,c);
  return 0;

}

/* 请在这里填写答案 */
double getArea(double a, double b, double c) {
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s -a) * (s - b) * (s -c));
    return area;
}

bool validate(double a, double b, double c) {
    if (a + b > c && a + c > b && b + c > a) {
        return true;
    }
    return false;
}