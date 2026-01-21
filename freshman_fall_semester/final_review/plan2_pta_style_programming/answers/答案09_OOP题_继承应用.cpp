#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const double PI = 3.14159;

class Shape {
protected:
    string name;
public:
    Shape(string n) : name(n) {}
    virtual double getArea() = 0;  // 纯虚函数
    void display() {
        cout << "Shape: " << name;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(string n, double r) : Shape(n), radius(r) {}
    
    double getArea() override {
        return PI * radius * radius;
    }
    
    void display() {
        Shape::display();  // 调用基类display
        cout << fixed << setprecision(1);
        cout << ", radius=" << radius 
             << ", area=" << setprecision(1) << getArea() << endl;
    }
};

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        string name;
        double radius;
        cin >> name >> radius;
        Circle circle(name, radius);
        circle.display();
    }
    
    return 0;
}

