#include <iostream>
#include <string>
#include <memory>
#include <utility>

using namespace std;

class Weapon {
public:
    string name;

    Weapon(const string& weaponName) {
        name = weaponName;
        cout << "'" << name << "' has been created." << endl;
    }

    ~Weapon() {
        cout << "'" << name << "' has benn destroyed." << endl;
    }

    void use() {
        cout << "'" << name << "' is being used." << endl;
    }
};

int main() {
    unique_ptr<Weapon> Excalibur = make_unique<Weapon>("sword_of_light");
    // unique_ptr<Weapon> another_sword = sword_of_light;
    // 这行代码会报错,智能指针可转移，但不可覆盖

    cout << "Calling use() via Excalibur:";
    Excalibur->use();

    unique_ptr<Weapon> transfer_station = nullptr;

    transfer_station = move(Excalibur);

    if (Excalibur == nullptr) {
        cout << "Excalibur is now nullptr." << endl;        
    }

    if (transfer_station != nullptr) {
        cout << "tranfer_station now owns the weapon." << endl;
        transfer_station->use();
    }

    return 0;
}