#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    int speed;
public:
    Vehicle() {
        speed = 0;
    }
    
    Vehicle(int initial_speed) {
        speed = initial_speed;
    }

    void accelerate(int speed_a) {
        speed += speed_a;
        cout << "加速！" << endl;
    }

    void brake(int speed_b) {
        speed -= speed_b;
        if (speed < 0) {
            speed = 0;
        }
        cout << "减速！" << endl;
    }
    
    virtual void displayInfo() {
        cout << "交通工具现在的速度是：" << speed << " km/h" << endl;
    }    

    int getSpeed() {
        return speed;
    }

    void setSpeed(int s) {
        speed = s;
    }
};

class Car : public Vehicle {
public:
    void displayInfo() override {
        cout << "这是一辆汽车，现在的速度是：" << speed << "km/h" << endl;
    }
};

class Bicycle : public Vehicle {
public:
    void displayInfo() override {
        cout << "这是一辆自行车，现在的速度是：" << speed << "km/h" << endl;
    }
};

int main() {
    Vehicle *vehiclePtr;
    Car myCar;
    Bicycle myBicycle;
    int car_speed_increase, car_speed_decrease;
    int bicycle_speed_increase, bicycle_speed_decrease;

    cout << "请输入汽车的加速值：";
    cin >> car_speed_increase;
    cout << "请输入汽车的减速值：";
    cin >> car_speed_decrease;

    cout << "请输入自行车的加速值：";
    cin >> bicycle_speed_increase;
    cout << "请输入自行车的减速值：";
    cin >> bicycle_speed_decrease;

    vehiclePtr = &myCar;
    vehiclePtr->accelerate(car_speed_increase);
    vehiclePtr->brake(car_speed_decrease);
    vehiclePtr->displayInfo();

    vehiclePtr = &myBicycle;
    vehiclePtr->accelerate(bicycle_speed_increase);
    vehiclePtr->brake(bicycle_speed_decrease);
    vehiclePtr->displayInfo();

}
