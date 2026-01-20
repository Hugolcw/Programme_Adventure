#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int student_id;
    int age;

public:
    Student() {
        name = "未知";
        student_id = 0;
        age = 0;
    }

    Student(string _name, int _student_id, int _age) {
        name = _name;
        student_id = _student_id;
        age = _age;
    }

    virtual void displayInfo() {
        cout << "这个学生的名字是：" << name <<endl;
        cout << "这个学生的学号是：" << student_id << endl;
        cout << "这个学生的年龄是：" << age << endl;
    }

    string getName() {
        return name;
    }

    int getSutdent_id() {
        return student_id;        
    }

    int getAge() {
        return age;
    }

    void setName(string n) {
        name = n;        
    }

    void setStudent_id(int id) {
        student_id = id;
    }

    void setAge(int a) {
        age = a;
    }
};

class Undergraduate : public Student {
private:
    string major;
public:

    // 子类的带参构造函数会调用父类的构造函数
    Undergraduate(string _name, int _student_id, int _age, string _major) 
        : Student(_name, _student_id, _age) {
            major = _major;
        }
    

    void setMajor(string m) {
        major = m;
    }




    string getMajor() {
            return major;
    }



    void displayInfo() {
        Student::displayInfo();
        cout << "这个同学的专业是：" << major << endl;
    }
};

int main() {
    Student stu1("一号", 1, 18);
    Student stu2("二号", 2, 18);
    Undergraduate stu3("三号", 3, 18, "txgc");
    
    Student *studentPtr;

    studentPtr = &stu1;
    studentPtr->displayInfo();

    studentPtr = &stu2;
    studentPtr->displayInfo();

    studentPtr = &stu3;
    studentPtr->displayInfo(); 
    

    return 0;
}