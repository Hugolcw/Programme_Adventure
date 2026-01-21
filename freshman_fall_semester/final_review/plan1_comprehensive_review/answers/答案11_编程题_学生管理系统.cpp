#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// 基类 Person
class Person {
protected:
    string name;
    int id;
public:
    Person(string name, int id) : name(name), id(id) {}
    virtual void display() = 0;  // 纯虚函数
    virtual ~Person() {}  // 虚析构函数
};

// 派生类 Student
class Student : public Person {
private:
    int scores[3];
public:
    Student(string name, int id, int s[]) : Person(name, id) {
        for (int i = 0; i < 3; i++) {
            scores[i] = s[i];
        }
    }
    
    void display() override {
        double sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += scores[i];
        }
        double avg = sum / 3.0;
        cout << name << " " << id << " " 
             << fixed << setprecision(1) << avg << endl;
    }
};

// 派生类 Teacher
class Teacher : public Person {
private:
    double salary;
public:
    Teacher(string name, int id, double salary) 
        : Person(name, id), salary(salary) {}
    
    void display() override {
        cout << name << " " << id << " " 
             << fixed << setprecision(2) << salary << endl;
    }
};

int main() {
    int n;
    cin >> n;
    
    Person* persons[10];  // 假设最多10个对象
    int idx = 0;
    
    // 输入学生信息
    for (int i = 0; i < n; i++) {
        string name;
        int id;
        int scores[3];
        cin >> name >> id >> scores[0] >> scores[1] >> scores[2];
        persons[idx++] = new Student(name, id, scores);
    }
    
    // 输入教师信息
    string name;
    int id;
    double salary;
    cin >> name >> id >> salary;
    persons[idx++] = new Teacher(name, id, salary);
    
    // 使用多态输出所有信息
    for (int i = 0; i < idx; i++) {
        persons[i]->display();
    }
    
    // 释放内存
    for (int i = 0; i < idx; i++) {
        delete persons[i];
    }
    
    return 0;
}

