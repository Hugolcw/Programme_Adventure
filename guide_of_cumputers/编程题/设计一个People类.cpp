#include <iostream>
#include <string>
using namespace std;

class People {
private:
    string name;
    int age;
    double height;
    double weight;
    static int count;

public:
    People(string n, int a, double h, double w) {
        name = n;
        age = a;
        height = h;
        weight = w;
        count++;
    }

    void displayPeople() {
        cout << name << " " << age << " " << height << " " << weight << endl;
    }

    static void displayCount() {
        cout << count << endl;
    }
};

int People::count = 0;

int main() {
    string name;
    int age;
    double height;
    double weight;
    while (true) {
        cin >> name;

        if (name == "exit") {
            break;
        }

        cin >> age >> height >> weight;

        People p(name, age, height, weight);
    }

    People::displayCount();

    return 0;
}