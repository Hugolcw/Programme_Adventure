#include <iostream>
#include <iomanip>

using namespace std;

const double PI = 3.14;

class Dot {
private:
    float x, y;
public:
    Dot(float xx, float yy) {
        x = xx;
        y = yy;
        cout << "Dot constructor called" << endl;
    }
    ~Dot() {
        cout << "Dot destructor called" << endl;
    }
};

class Cir : public Dot {
private:
    float r;
public:
    Cir(float x, float y, float r) : Dot(x, y) {
        this->r = r;
        cout << "Cir constructor called" << endl;
    }

    ~Cir() {
        cout << "Cir destructor called" << endl;
    }

    float getArea() {
        return r * r * PI;
    }
};

int main(){
    float x,y,r;
    cin>>x>>y>>r;
    Cir c(x,y,r);
    cout<<fixed<<setprecision(2)<<c.getArea()<<endl;
    return 0;
}