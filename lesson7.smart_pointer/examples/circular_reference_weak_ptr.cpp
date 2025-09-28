#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Apartment;

class Person {
public:
    string name;
    shared_ptr<Apartment> apartment;

    Person(const string& n) :name(n) {
        cout << "Person '" << name << "' is created." << endl;
    }

    ~Person() {
        cout << "Person '" << name << "' is destroyed. !!!" << endl;
    }
};

class Apartment {
public:
    string unit;
    shared_ptr<Person> tenant;

    Apartment(const string& u) : unit(u) {
        cout << "Apartment '" << unit << "' is created." << endl;
    }

    ~Apartment() {
        cout << "Apartment '" << unit << "' is destroyed. !!!" << endl;
    }
};

int main() {
    cout << "--- Entering the main logic ---" << endl;
    {
        // 1.创建 Person 和 Apartment 对象
        shared_ptr<Person> alice = make_shared<Person>("Alice");
        shared_ptr<Apartment> apt101 = make_shared<Person>("101");

        cout << "Initial ref counts:" << endl;
        cout << "Alice's ref count:" << alice.use_count() << endl;
        cout << "Apt101's ref count:" << apt101.use_count() << endl;
        cout << endl;

        // 2.将他们互相应用，形成一个环
        cout << "--- Linking them together..." << endl;
        alice->apartment = apt101;
        apt101->tenant = alice;

        cout << "Ref count after linking:" << endl;
        cout << "Alice's ref count:" << alice.use_count() << endl;
        cout << "Apt101's ref count:" << apt101.use_count() << endl;
        cout << endl;
        
        cout << "--- Exiting the inner scope..." << endl;
    } // alice 和 apt101 两个智能指针在这里被销毁

    cout << "\n--- After the inner scope, main is about to end. ---" << endl;
    cout << "--- Observe if the destructors were called. ---" << endl;

    return 0;
}