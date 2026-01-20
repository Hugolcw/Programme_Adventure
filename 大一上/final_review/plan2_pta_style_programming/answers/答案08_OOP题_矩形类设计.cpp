#include <iostream>
#include <iomanip>
using namespace std;

class Rectangle {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }
    
    double getArea() {
        return width * height;
    }
    
    double getPerimeter() {
        return 2 * (width + height);
    }
    
    void display() {
        cout << fixed << setprecision(1);
        cout << "Rectangle: width=" << width 
             << ", height=" << height 
             << ", area=" << getArea() 
             << ", perimeter=" << getPerimeter() << endl;
    }
};

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        double w, h;
        cin >> w >> h;
        Rectangle rect(w, h);
        rect.display();
    }
    
    return 0;
}

