#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Person;

class Apartment
{
public:
    string unit;

    weak_ptr<Person> tenant;

    Apartment(const string &u) : unit(u)
    {
        cout << "Apartment '" << unit << "' is created." << endl;
    }

    ~Apartment()
    {
        cout << "Apartment '" << unit << "' is destoryed." << endl;
    }
};

class Person
{
public:
    string name;

    shared_ptr<Apartment> apartment;

    Person(const string &n) : name(n)
    {
        cout << "Person '" << name << "' is created." << endl;
    }

    ~Person()
    {
        cout << "Person '" << name << "' is destoryed." << endl;
    }
};

int main()
{
    cout << "--- Entering the main logic ---" << endl;
    {
        shared_ptr<Person> alice = make_shared<Person>("Alice");
        shared_ptr<Apartment> apt101 = make_shared<Apartment>("101");

        cout << "Initial ref counts:" << endl;
        cout << "Alice's ref count:" << alice.use_count() << endl;
        cout << "Apt101's ref count:" << apt101.use_count() << endl;
        cout << endl;

        cout << "--- Linking them together..." << endl;
        alice->apartment = apt101;
        apt101->tenant = alice;

        cout << "Ref counts after linking:" << endl;
        cout << "Alice's ref count:" << alice.use_count() << endl;
        cout << "Apt101's ref count:" << apt101.use_count() << endl;
        cout << endl;

        cout << "--- Exiting the inner scope..." << endl;
    }

    cout << "\n--- After the inner scope, main is about to end. ---" << endl;
    cout << "--- Observe if the destructors were called THIS TIME. ---" << endl;

    return 0;
}