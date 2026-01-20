#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Weapon {
public:
    string name;

    Weapon(const string& weaponName) {
        name = weaponName;
        cout << "'" << name << "' has been created." << endl;        
    }

    ~Weapon() {
        cout << "'" << name << "' has been destroyed." << endl;
    }

    void use() {
        cout << "'" << name << "' is being used." << endl;
    }
};

int main() {
    shared_ptr<Weapon> Excalibur = make_shared<Weapon>("Excalibur");
    cout << "Initial creation. Ref count: " << Excalibur.use_count() << endl;
    Excalibur->use();
    cout << endl;

    cout << "Creating a second pointer..." << endl;
    shared_ptr<Weapon> secondWielder = Excalibur;
    cout << "After copy 1. Ref count: " << Excalibur.use_count() << endl;
    secondWielder->use();
    cout << endl;

    cout << "Entering a new scope to create a third pointer..." << endl;
    {
        shared_ptr<Weapon> thirdWielder = Excalibur;
        cout << "Inside scope. Ref count: " << Excalibur.use_count() << endl;
        thirdWielder->use();

        cout << "Exiting scope now. thirdWielder will be destroyed." << endl;
    }

    cout << "After exiting scope. Ref count: " << Excalibur.use_count() << endl;
    cout << "Object can still be used by original pointers:" << endl;
    Excalibur->use();
    cout << endl;

    cout << "main function is about to end." << endl;
    return 0;
}