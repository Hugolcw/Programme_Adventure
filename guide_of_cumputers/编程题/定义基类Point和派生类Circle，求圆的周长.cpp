#include <iostream>
#include <iomanip>
using namespace std;

class Point {
private:
    float x, y;
public:
    Point(float x, float y) {
        this->x = x;
        this->y = y;
        cout << "Point constructor called" << endl;
    }
    
    ~Point() {
        cout << "Point destructor called" << endl;
    }
};

class Circle : public Point {
private:
    float r;
public:
    Circle(float x, float y, float r) : Point(x, y) {
        this->r = r;
        cout << "Circle constructor called" << endl;
    }
    
    ~Circle() {
        cout << "Circle destructor called" << endl;
    }

    float getCircumference() {
        return 2 * r * 3.14;
    }
};

int main()
{
    float x,y,r;
    cin>>x>>y>>r;
    Circle c(x,y,r);
    cout<<fixed<<setprecision(2)<<c.getCircumference()<<endl;
    return 0;
}